(function($, Drupal, document, window){

$(document).ready(function(){

  $('#main-menu-toggle').toggle(function(){
    $('#main-menu-container #main-menu').show();
    return false;
  }, function(){
    $('#main-menu-container #main-menu').hide();
    return false;
  });

});

})(jQuery, Drupal, document, window);
