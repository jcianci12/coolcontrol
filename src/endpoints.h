#include <ESPAsyncWebServer.h>
#include <form.h>
#include "AsyncJson.h"

const char *PARAM_INPUT_1 = "input1";
AsyncWebServer server(80);

Servo myservo; // create servo object to control a servo

// int newval; // variable to read the value from the analog pin
// int oldval;
// const size_t CAPACITY = JSON_OBJECT_SIZE(5);
// StaticJsonDocument<CAPACITY> doc;

class Endpoints
{

private:
    static int newval;
    static int oldval;

public:
    Endpoints() {}
    Endpoints(int n, int o)
    {
        newval = n;
        oldval = o;
    }
    int getNewVal()
    {
        return newval;
    }

    void setNewVal(int val)
    {
        newval = val;
    }

    int getOldVal()
    {
        return oldval;
    }

    void setOldVal(int val)
    {
        oldval = val;
    }

    void InitEndpoints()
    {
        // Send web page with input fields to client
        server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                  { 
                Serial.println("request received!");
                request->send_P(200, "text/html", index_html); });
        // Send web page with input fields to client
        server.on("/reset", HTTP_GET, [](AsyncWebServerRequest *request)
                  { 
                Serial.println("request received!");
                //resetwifi();
                request->send_P(200, "text/html", index_html); });

        server.onRequestBody(
            [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
            {
                if ((request->url() == "/update") &&
                    (request->method() == HTTP_POST))
                {
                    const size_t JSON_DOC_SIZE = 512U;
                    DynamicJsonDocument jsonDoc(JSON_DOC_SIZE);

                    if (DeserializationError::Ok == deserializeJson(jsonDoc, (const char *)data))
                    {
                        JsonObject obj = jsonDoc.as<JsonObject>();
                        newval = obj[PARAM_INPUT_1];
                        Serial.println("value recieved");
                        Serial.println(newval);

                        // LOG_INFO("%s", obj["test"].as<String>().c_str());
                    }

                    request->send(200, "application/json", "{ \"status\": 0 }");
                }
            });

        server.begin();
    }

    int readInputVal()
    {
        Serial.println(newval);
        return newval;
    }
};
