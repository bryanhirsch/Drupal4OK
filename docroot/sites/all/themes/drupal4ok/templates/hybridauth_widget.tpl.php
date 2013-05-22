<h3>Login with your social profile</h3>
<?php
  print theme('item_list',
    array(
      'items' => $providers,
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => array('hybridauth-widget')),
    )
  );
?>