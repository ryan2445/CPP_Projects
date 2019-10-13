//Ryan Hoffman - CS202 - Project 4
#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor{

public:
Sensor();
Sensor(char * type);
Sensor(Sensor & sensor);

void setType(char * type);
void setExtraCost(float extracost);

char * getType();
float getExtraCost();

static void resetGps_cnt();
static void resetCamera_cnt();
static void resetLidar_cnt();
static void resetRadar_cnt();

static int getGps_cnt();
static int getCamera_cnt();
static int getLidar_cnt();
static int getRadar_cnt();

static int getTotalGps();
static int getTotalCamera();
static int getTotalLidar();
static int getTotalRadar();

private:
char m_type[256];
float m_extracost;
static int gps_cnt;
static int camera_cnt;
static int lidar_cnt;
static int radar_cnt;

static int totalGps_sensors;
static int totalCamera_sensors;
static int totalLidar_sensors;
static int totalRadar_sensors;
};
#endif
