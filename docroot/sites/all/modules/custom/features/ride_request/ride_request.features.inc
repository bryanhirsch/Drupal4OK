<?php
/**
 * @file
 * ride_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ride_request_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ride_request_node_info() {
  $items = array(
    'ride_request' => array(
      'name' => t('Ride Request'),
      'base' => 'node_content',
      'description' => t('Request a ride'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
