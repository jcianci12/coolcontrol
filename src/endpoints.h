#include <ESPAsyncWebServer.h>
#include <form.h>
#include "AsyncJson.h"

const char *PARAM_INPUT_1 = "input1";
AsyncWebServer server(80);

Servo myservo; // create servo object to control a servo

int newval; // variable to read the value from the analog pin
int oldval;
// const size_t CAPACITY = JSON_OBJECT_SIZE(5);
// StaticJsonDocument<CAPACITY> doc;

class Endpoints
{
public:
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

public:
    static int readInputVal()
    {
        Serial.println(newval);
        return newval;
    }
};

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