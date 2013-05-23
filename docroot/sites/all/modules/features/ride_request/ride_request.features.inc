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
 * Implements hook_flag_default_flags().
 */
function ride_request_flag_default_flags() {
  $flags = array();
  // Exported flag: "Give Ride".
  $flags['give_ride'] = array(
    'content_type' => 'node',
    'title' => 'Give Ride',
    'global' => 0,
    'types' => array(
      0 => 'ride_request',
    ),
    'flag_short' => 'Give Ride',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Cancel Ride',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ride_request',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

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
