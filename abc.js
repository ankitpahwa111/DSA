exports.apply = function(input, cb) {
    if (typeof input == 'string'){
          cb("Please provide a JSON-formatted Array or Object", null);
    } else if (Array.isArray(input)) {
          var result = {
              "datatype":"array",
              "sum": sum(input)
          }
          cb(null, result);
    } else if (input["values"] && Array.isArray(input["values"])) {
          var result = {
              "datatype":"object",
              "sum": sum(input['values'])
          }
          cb(null, result);
    } else {
        cb("Please provide an Array of \"values\"", null);
    }
  };
  
  var sum = function(arr) {
      return arr.reduce( function(a,b) {return a+b;} );
  }