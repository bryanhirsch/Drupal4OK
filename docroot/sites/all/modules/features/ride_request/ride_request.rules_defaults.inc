<?php
/**
 * @file
 * ride_request.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ride_request_default_rules_configuration() {
  $items = array();
  $items['rules_give_ride_workflow'] = entity_import('rules_config', '{ "rules_give_ride_workflow" : {
      "LABEL" : "Give Ride Workflow",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_give_ride" ],
      "DO" : [ { "redirect" : { "url" : "ride-confirmation" } } ]
    }
  }');
  return $items;
}
