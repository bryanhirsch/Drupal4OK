<?php
/**
 * @file
 * dr_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dr_rules_default_rules_configuration() {
  $items = array();
  $items['rules_add_content_redirect_to_login_bundles'] = entity_import('rules_config', '{ "rules_add_content_redirect_to_login_bundles" : {
      "LABEL" : "Add content redirect to login - bundles",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_view" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : {
                "ride_request" : "ride_request",
                "housing_have" : "housing_have",
                "housing_need" : "housing_need"
              }
            }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "In order to post on the site, please create an account or login." } },
        { "redirect" : { "url" : "user\\/login", "destination" : 1 } }
      ]
    }
  }');
  $items['rules_add_content_redirect_to_login_node_add'] = entity_import('rules_config', '{ "rules_add_content_redirect_to_login_node_add" : {
      "LABEL" : "Add content redirect to login - Node add",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "init" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        },
        { "AND" : [
            { "text_matches" : {
                "text" : [ "site:current-page:path" ],
                "match" : "node\\/add",
                "operation" : "starts"
              }
            },
            { "OR" : [] },
            { "text_matches" : {
                "text" : [ "site:current-page:path" ],
                "match" : "housing-request\\/",
                "operation" : "starts"
              }
            },
            { "OR" : [] },
            { "text_matches" : {
                "text" : [ "site:current-page:path" ],
                "match" : "housing-available\\/",
                "operation" : "starts"
              }
            },
            { "OR" : [] },
            { "text_matches" : {
                "text" : [ "site:current-page:path" ],
                "match" : "ride-request\\/",
                "operation" : "starts"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "In order to post on the site, please create an account or login." } },
        { "redirect" : { "url" : "user\\/login", "destination" : 1 } }
      ]
    }
  }');
  return $items;
}
