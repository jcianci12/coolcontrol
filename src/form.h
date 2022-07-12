
const char index_html[] PROGMEM = R"rawliteral(


<!DOCTYPE HTML>
<html>

<head>
    <title>ESP Input Form</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>

    <div class="slidecontainer">
        <input type="range" min="0" max="100" value="50" class="slider" id="myRange">
        <h1>Percent open: <span id="demo"></span></h1>

    </div>
    <a href="reset">Reset. (This will reset the device and create a fresh access point that you can connect to in order to configure for a new WiFi.)</a>
    <style>
        .slidecontainer {
            width: 100%;
            /* Width of the outside container */
        }

        /* The slider itself */
        .slider {
            -webkit-appearance: none;
            /* Override default CSS styles */
            appearance: none;
            width: 100%;
            /* Full-width */
            height: 25px;
            /* Specified height */
            background: #d3d3d3;
            /* Grey background */
            outline: none;
            /* Remove outline */
            opacity: 0.7;
            /* Set transparency (for mouse-over effects on hover) */
            -webkit-transition: .2s;
            /* 0.2 seconds transition on hover */
            transition: opacity .2s;
        }

        /* Mouse-over effects */
        .slider:hover {
            opacity: 1;
            /* Fully shown on mouse-over */
        }

        /* The slider handle (use -webkit- (Chrome, Opera, Safari, Edge) and -moz- (Firefox) to override default look) */
        .slider::-webkit-slider-thumb {
            -webkit-appearance: none;
            /* Override default look */
            appearance: none;
            width: 25px;
            /* Set a specific slider handle width */
            height: 25px;
            /* Slider handle height */
            background: #04AA6D;
            /* Green background */
            cursor: pointer;
            /* Cursor on hover */
        }

        .slider::-moz-range-thumb {
            width: 25px;
            /* Set a specific slider handle width */
            height: 25px;
            /* Slider handle height */
            background: #04AA6D;
            /* Green background */
            cursor: pointer;
            /* Cursor on hover */
        }
    </style>
    <script>
        var slider = document.getElementById("myRange");
        var output = document.getElementById("demo");
        var value;
        output.innerHTML = slider.value; // Display the default slider value

        // Update the current slider value (each time you drag the slider handle)
        slider.oninput = function () {
            value = this.value
            output.innerHTML = value;

           processChanges()

        }

        function debounce(func, timeout = 20) {
            let timer;
            return (...args) => {
                clearTimeout(timer);
                timer = setTimeout(() => { func.apply(this, args); }, timeout);
            };
        }
        const processChanges = debounce(() => postData());

        function postData() {
            post("/update", { input1: this.value }, "post")

        }
        /**
         * sends a request to the specified url from a form. this will change the window location.
         * @param {string} path the path to send the post request to
         * @param {object} params the parameters to add to the url
         * @param {string} [method=post] the method to use on the form
         */
        function post(path, params, method) {

            // The rest of this code assumes you are not using a library.
            // It can be made less verbose if you use one.
            const form = document.createElement('form');
            form.method = method;
            form.action = path;

            // // collect the form data while iterating over the inputs
            // var data = {};
            // for (var i = 0, ii = form.length; i < ii; ++i) {
            //     var input = form[i];
            //     if (input.name) {
            //         data[input.name] = input.value;
            //     }
            // }

            document.body.appendChild(form);
            //form.submit();
            // construct an HTTP request
            var xhr = new XMLHttpRequest();
            xhr.open(form.method, form.action, true);
            xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8');

            // send the collected data as JSON
            xhr.send(JSON.stringify(params));

            xhr.onloadend = function () {
                // done
            };
        }

    </script>
</body>

</html>




)rawliteral";