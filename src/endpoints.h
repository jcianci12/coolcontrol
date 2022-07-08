  #include <ESPAsyncWebServer.h>
#include <form.h>
#include <servoFunctions.h>
 #include "AsyncJson.h"

const char *PARAM_INPUT_1 = "input1";
AsyncWebServer server(80);

// const size_t CAPACITY = JSON_OBJECT_SIZE(5);
// StaticJsonDocument<CAPACITY> doc;


void notFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}
void initEndpoints()
{
    // Send web page with input fields to client
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { 
                Serial.println("request received!");
                request->send_P(200, "text/html", index_html); });

    // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>

    //    AsyncCallbackJsonWebHandler* handler = new AsyncCallbackJsonWebHandler("/update", [](AsyncWebServerRequest *request, JsonVariant &json) {

    //   doc = json.as<JsonObject>();
    //   String world = doc[PARAM_INPUT_1];
    // val = world.toInt();
    //   // ...
    // });

    server.onRequestBody(
        [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
        {
            if ((request->url() == "/update") &&
                (request->method() == HTTP_POST))
            {
                const size_t        JSON_DOC_SIZE   = 512U;
                DynamicJsonDocument jsonDoc(JSON_DOC_SIZE);
                
                if (DeserializationError::Ok == deserializeJson(jsonDoc, (const char*)data))
                {
                    JsonObject obj = jsonDoc.as<JsonObject>();
                    val = obj[PARAM_INPUT_1];
                    Serial.println("value recieved");
                    Serial.println(val);

                    //LOG_INFO("%s", obj["test"].as<String>().c_str());
                }

                request->send(200, "application/json", "{ \"status\": 0 }");
            }
        }
    );

    server.begin();
}

int readInputVal()
{
    Serial.println(val);
    return val;
}