<?php
/**
 * @file
 * housing_have.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function housing_have_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|housing_have|default';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'housing_have';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '2',
    'children' => array(
      0 => 'field_no_beds',
      1 => 'field_house_details',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'classes' => 'basics',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_basics|node|housing_have|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|housing_have|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'housing_have';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '2',
    'children' => array(
      0 => 'field_date_from',
      1 => 'field_no_beds',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_basics|node|housing_have|form'] = $field_group;

  return $export;
}
