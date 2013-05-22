(function($, Drupal, document, window){

$(document).ready(function(){

  $('body').addClass('lt-ie9');

  $('#main-menu-toggle').click(function(){
    $('ul', this).toggleClass('active');
  });

});

})(jQuery, Drupal, document, window);
