<?php
/**
 * @file
 * housing_have.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function housing_have_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'have_bed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Have Bed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'The people, hotels and B&B\'s below can host you.';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h3>If you need housing, you are in the right place. If you don\'t see a match, post a request <a href="/node/add/housing-need">here.</a></h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<h3>If you don\'t see a match, post a request <a href="/node/add/housing-need">here.</a></h3>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: House Details */
  $handler->display->display_options['fields']['field_house_details']['id'] = 'field_house_details';
  $handler->display->display_options['fields']['field_house_details']['table'] = 'field_data_field_house_details';
  $handler->display->display_options['fields']['field_house_details']['field'] = 'field_house_details';
  $handler->display->display_options['fields']['field_house_details']['label'] = '';
  $handler->display->display_options['fields']['field_house_details']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_house_details']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_house_details']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_house_details]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'housing_have' => 'housing_have',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: House Details (field_house_details) */
  $handler->display->display_options['filters']['field_house_details_value']['id'] = 'field_house_details_value';
  $handler->display->display_options['filters']['field_house_details_value']['table'] = 'field_data_field_house_details';
  $handler->display->display_options['filters']['field_house_details_value']['field'] = 'field_house_details_value';
  $handler->display->display_options['filters']['field_house_details_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_house_details_value']['expose']['operator_id'] = 'field_house_details_value_op';
  $handler->display->display_options['filters']['field_house_details_value']['expose']['label'] = 'I need a house that would:';
  $handler->display->display_options['filters']['field_house_details_value']['expose']['operator'] = 'field_house_details_value_op';
  $handler->display->display_options['filters']['field_house_details_value']['expose']['identifier'] = 'field_house_details_value';
  $handler->display->display_options['filters']['field_house_details_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_house_details_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Have Bed */
  $handler = $view->new_display('page', 'Have Bed', 'page');
  $handler->display->display_options['path'] = 'housing/have';
  $export['have_bed'] = $view;

  $view = new view();
  $view->name = 'need_bed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Need Bed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'The people below need a place to sleep.';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_preferences_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h3>If you can host people, you are in the right place. If you don\'t see a match, post an offer <a href="/node/add/housing-have">here.</a></h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<h3>If you don\'t see a match, post an offer <a href="/node/add/housing-have">here.</a></h3>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: I need a house that: */
  $handler->display->display_options['fields']['field_preferences']['id'] = 'field_preferences';
  $handler->display->display_options['fields']['field_preferences']['table'] = 'field_data_field_preferences';
  $handler->display->display_options['fields']['field_preferences']['field'] = 'field_preferences';
  $handler->display->display_options['fields']['field_preferences']['label'] = '';
  $handler->display->display_options['fields']['field_preferences']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_preferences']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_preferences']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Needs housing that [field_preferences]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'housing_need' => 'housing_need',
  );
  /* Filter criterion: Content: I need a house that: (field_preferences) */
  $handler->display->display_options['filters']['field_preferences_value']['id'] = 'field_preferences_value';
  $handler->display->display_options['filters']['field_preferences_value']['table'] = 'field_data_field_preferences';
  $handler->display->display_options['filters']['field_preferences_value']['field'] = 'field_preferences_value';
  $handler->display->display_options['filters']['field_preferences_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_preferences_value']['expose']['operator_id'] = 'field_preferences_value_op';
  $handler->display->display_options['filters']['field_preferences_value']['expose']['label'] = 'My housing:';
  $handler->display->display_options['filters']['field_preferences_value']['expose']['operator'] = 'field_preferences_value_op';
  $handler->display->display_options['filters']['field_preferences_value']['expose']['identifier'] = 'field_preferences_value';
  $handler->display->display_options['filters']['field_preferences_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_preferences_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'housing/need';
  $export['need_bed'] = $view;

  return $export;
}
