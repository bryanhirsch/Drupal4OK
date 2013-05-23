<?php
/**
 * @file
 * ride_request.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ride_request_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:ride/need
  $menu_links['main-menu:ride/need'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ride/need',
    'router_path' => 'ride/need',
    'link_title' => '<strong>I Need</strong> a Ride',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'need',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('<strong>I Need</strong> a Ride');


  return $menu_links;
}
