(function( $ ) {
    $.fn.noClickDelay = function() {
        var $wrapper = this;
        var $target = this;
        var moved = false;

        var onMouseDown = function(e) {
            e.preventDefault();
            moved = false;
            $target = $(e.target);
            if($target.nodeType == 3) {
                $target = $($target.parent());
            }
            $target.addClass('pressed');

            var onMouseMove = function(e) {
                moved = true;
                $target.removeClass('pressed');
            };

            $wrapper.bind('touchmove', onMouseMove);
            $wrapper.bind('mousemove', onMouseMove);

            var onMouseUp = function(e) {
                $wrapper.unbind('mousemove');
                $wrapper.unbind('touchmove');
                $wrapper.unbind('mouseup');
                $wrapper.unbind('touchend');
                if(!moved && $target.length) {
                    $target.removeClass('pressed');
                    $target.trigger('click');
                    $target.focus();
                }
            };

            $wrapper.bind('touchend', onMouseUp);
            $wrapper.bind('mouseup', onMouseUp);
        };

        $wrapper.bind('touchstart', onMouseDown);
        $wrapper.bind('mousedown', onMouseDown);
    };
})( jQuery );