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
  $items['rules_add_content_redirect_to_login'] = entity_import('rules_config', '{ "rules_add_content_redirect_to_login" : {
      "LABEL" : "Add content redirect to login",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "init" ],
      "IF" : [
        { "text_matches" : {
            "text" : [ "site:current-page:path" ],
            "match" : "node\\/add",
            "operation" : "starts"
          }
        },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Please create an account or login." } },
        { "redirect" : { "url" : "user\\/login", "destination" : 1 } }
      ]
    }
  }');
  return $items;
}
