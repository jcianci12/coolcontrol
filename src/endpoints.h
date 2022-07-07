#include <ESPAsyncWebServer.h>
#include <form.h>
#include <servoFunctions.h>
#include "AsyncJson.h"
#include "ArduinoJson.h"

const char *PARAM_INPUT_1 = "input1";

// const size_t CAPACITY = JSON_OBJECT_SIZE(5);
// StaticJsonDocument<CAPACITY> doc;

AsyncWebServer server(80);

void mainUpdateJson()
{
    StaticJsonDocument<200> doc; // document has to be bigger than the space required for the output json text.
    val = doc[PARAM_INPUT_1];
    Serial.println(val);
}

void notFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}
void initEndpoints()
{
    // Send web page with input fields to client
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send_P(200, "text/html", index_html); });

    // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>

    //    AsyncCallbackJsonWebHandler* handler = new AsyncCallbackJsonWebHandler("/update", [](AsyncWebServerRequest *request, JsonVariant &json) {

    //   doc = json.as<JsonObject>();
    //   String world = doc[PARAM_INPUT_1];
    // val = world.toInt();
    //   // ...
    // });

    server.on("/update", [](AsyncWebServerRequest *request)
              {
  mainUpdateJson();
  //request->send_P(200, "text/plain", "{done:success}");
  //doc = json.as<JsonObject>();
  //String world = doc[PARAM_INPUT_1];
  
//val = json[PARAM_INPUT_1];
  // ... });

    // server.addHandler(handler); })
})
int readInputVal()
{
    Serial.println(val);
    return val;
}