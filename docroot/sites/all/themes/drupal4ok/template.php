<?php

function drupal4ok_links__system_main_menu($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,

          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page())) && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';
      $link['html'] = true;
      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 *
 *
 */
function drupal4ok_theme($existing, $type, $theme, $path)
{
    $items = array();

    $items['user_login'] = array(
        'render element' => 'form',
        'path' => drupal_get_path('theme', 'drupal4ok') . '/templates',
        'template' => 'user-login',
    );

    $items['user_register_form'] = array(
        'render element' => 'form',
        'path' => drupal_get_path('theme', 'drupal4ok') . '/templates',
        'template' => 'user-register',
    );

    return $items;
}

 function drupal4ok_preprocess_page(&$vars) 
 {
  if(arg(0) != 'admin') {
    drupal_add_js("
    (function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
    new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
    j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
    '//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
    })(window,document,'script','dataLayer','GTM-5X3L');
      ",
      array('type' => 'inline', 'scope' => 'header', 'every_page' => TRUE, 'weight' => 4));
  }
}

function drupal4ok_node_preview($variables) {
  $node = $variables['node'];
  $output = '<div class="preview">';
  if (in_array($node->type, array('housing_need'))) {
    $elements = node_view($node, 'full');
    $full = drupal_render($elements);
    $output .= '<h3 class="post-preview" >' . t('Preview of your posting') . '</h3>';
    $output .= $full;
  } else {
    $preview_trimmed_version = FALSE;
    $elements = node_view(clone $node, 'teaser');
    $trimmed = drupal_render($elements);
    $elements = node_view($node, 'full');
    $full = drupal_render($elements);
    // Do we need to preview trimmed version of post as well as full version?
    if ($trimmed != $full) {
      drupal_set_message(t('The trimmed version of your post shows what your post looks like when promoted to the main page or when exported for syndication.<span class="no-js"> You can insert the delimiter "&lt;!--break--&gt;" (without the quotes) to fine-tune where your post gets split.</span>'));
      $output .= '<h3>' . t('Preview trimmed version') . '</h3>';
      $output .= $trimmed;
      $output .= '<h3>' . t('Preview full version') . '</h3>';
      $output .= $full;
    }
    else {
      $output .= $full;
    }
  }
  $output .= "</div>\n";
  return $output;
}
