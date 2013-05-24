<?php
/**
 * @file
 * housing_have.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function housing_have_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function housing_have_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function housing_have_node_info() {
  $items = array(
    'housing_have' => array(
      'name' => t('a Place to Stay'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => t('<p><strong>Privacy Statement</strong><br />
The information collected on this form is used by help4ok.net to allow us to match someone who has housing available with someone who requires housing. The information collected on this form is displayed on the website. You can update or remove this information at any time by returning to this website. Your information will not be used for any other purpose other than that noted above.</p>'),
    ),
    'housing_need' => array(
      'name' => t('a Request to Stay'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
