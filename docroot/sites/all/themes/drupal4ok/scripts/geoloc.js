/**
 * Geolocation library
 * 
 * Usage:
 * var x = new GeoLoc();
 * x.attemptLocate(function(lat, lon, confidence){});
 *
 * where
 *   lat = latitude
 *   lon = longitude
 *   confidence = how accurate the coordinates are
 *     2 = very confident (used built-in geolocation),  
 *     1 = less confident (used IP-based API), 
 *     0 = couldn't find anything
 */
var GeoLoc = function() {
  
  var that = {}, priv = {}, confidence = 0;

  /**
   * Attempt to find location.
   * @param callback that accepts (lat, lon, confidence) as args
   */
  that.attemptLocate = function(func) {
    func = !!func ? func : function(){};

    var callback = function(position) {
      that.respondToLocation(position, func);
    };

    var geoLocation = priv.tryGeolocation(callback);
  };

  /**
   * Gets current confidence
   * @return confidence value
   */
  that.getConfidence = function() {
    return confidence;
  };

  /**
   * Basic responder
   * @param position object
   * @param callback that accepts (lat, lon, confidence) as args
   */
  that.respondToLocation = function(position, callback) {
    var lat = position.coords.latitude;
    var lon = position.coords.longitude;

    callback(lat, lon, confidence);
  };

  /**
   * PRIVATE: Generate XHR request object
   * @return XHR object
   */
  priv.xhr = function() {
    var ref = null;
    if (!!window.XMLHttpRequest) {
      ref = new XMLHttpRequest();
    } else if (window.ActiveXObject) {
      ref = new ActiveXObject("MSXML2.XMLHTTP.3.0");
    }
    return ref;
  };

  /**
   * PRIVATE: Try geolocation call
   * @param callback function
   */
  priv.tryGeolocation = function(callback) {
    if (!!navigator.geolocation) {
      navigator.geolocation.getCurrentPosition(callback, function(){
        priv.tryAPI(callback);
      });
      confidence = 2;
      return true;
    }
    return false;
  };

  /**
   * PRIVATE: Try API call
   * @param callback function
   */
  priv.tryAPI = function(callback) {
    var xhr = priv.xhr();

    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4){
        var data = this.responseXML.querySelectorAll("Response")[0];

        if (data.querySelectorAll('Ip').length > 0) {
          confidence = 1;
        }

        var position = {
          coords: {
            latitude: confidence > 0 ? data.querySelectorAll('Latitude')[0].textContent : 0,
            longitude: confidence > 0 ? data.querySelectorAll('Longitude')[0].textContent : 0
          }
        };

        callback(position);
      }
    };

    xhr.open('GET', 'http://freegeoip.net/xml/', true);
    xhr.setRequestHeader('X-Requested-With', 'XMLHttpRequest');
    xhr.send(null);
  };

  return that;

};
