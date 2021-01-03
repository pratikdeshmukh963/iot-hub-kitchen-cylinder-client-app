#include <ArduinoJson.h>
#include "HX711.h"

#if SIMULATED_DATA

void initSensor()
{
    // use SIMULATED_DATA, no sensor need to be inited
}

float readWeight()
{
    return random(15999, 30000);
}

#else

HX711 scale;
void initSensor()
{
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale();
    scale.tare();
    /*
     * Currently this value is coded into the device but we can also configure 
     * it using any home assistant if required.
     * TODO: One easy way would be using devices' own weight
     *  - A certain amount of delay after tare lets say 20sec.
     *  - Put the machine upside down so that it's own weight can be used to 
     *    find scale value.
     *  - We can use device own reading and get away without any delays.
     */
    scale.set_scale(-24.6);
}

int readWeight()
{
    float reading = 0;
    if (scale.is_ready()) {
        reading = scale.get_units(5);
        Serial.print("Weight: ");
        Serial.println(reading);
    }
    else
    {
        Serial.println("HX711 not found.");
    }
    return round(reading);
}

#endif

bool readMessage(char *payload)
{
    int weight = readWeight();
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.createObject();
    root["deviceId"] = DEVICE_ID;
    bool weightAlert = false;

    // NAN is not the valid json, change it to NULL
    if (std::isnan(weight) || weight == 0)
    {
        root["weight"] = NULL;
    }
    else
    {
        root["weight"] = weight;
        // FIXME: Currently not used. Analytics done at cloud side
        if (weight < WEIGHT_ALERT)
        {
            weightAlert = true;
        }
    }

    root.printTo(payload, MESSAGE_MAX_LEN);
    return weightAlert;
}
