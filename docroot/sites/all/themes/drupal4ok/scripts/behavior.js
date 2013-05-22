(function($, Drupal, document, window){

$(document).ready(function(){

  $('label[for="main-menu-toggle"]').noClickDelay();

  $('#main-menu-toggle').click(function(){
    if ($(this).attr('checked')) {
      $(this).removeAttr('checked');
    }
    else {
      $(this).attr('checked', 'checked');
    }
  });

});

})(jQuery, Drupal, document, window);
