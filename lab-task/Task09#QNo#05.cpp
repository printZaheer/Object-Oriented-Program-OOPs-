#include <iostream>
#include <string>
using namespace std;
class CloudResource {
protected:
    string resourceID;
    double baseHourlyRate;
    string* metadata;
public:
    CloudResource(string id, double rate) {
        resourceID = id;
        baseHourlyRate = rate;
        metadata = new string("Region: us-east");
        cout << "CloudResource constructor called" << endl;
    }
    virtual ~CloudResource() {
        delete metadata;
        cout << "CloudResource destructor called" << endl;
    }
    virtual double calculateCost(double hours) {
        return baseHourlyRate * hours;
    }
};
class ServerInstance : public CloudResource {
protected:
    int cpuCores;
    double ramGB;
    string* serverMetadata;
public:
    ServerInstance(string id, double rate, int cores, double ram) : CloudResource(id, rate) {
        cpuCores = cores;
        ramGB = ram;
        serverMetadata = new string("OS: Linux");
        cout << "ServerInstance constructor called" << endl;
    }
    ~ServerInstance() {
        delete serverMetadata;
        cout << "ServerInstance destructor called" << endl;
    }
    double calculateCost(double hours) {
        return (baseHourlyRate + (cpuCores * 0.05) + (ramGB * 0.02)) * hours;
    }
};
class GPUAcceleratedServer : public ServerInstance {
private:
    int gpuCount;
    double gpuModelTierMultiplier;
    string* gpuMetadata;
public:
    GPUAcceleratedServer(string id, double rate, int cores, double ram, int gpus, double tier)
        : ServerInstance(id, rate, cores, ram) {
        gpuCount = gpus;
        gpuModelTierMultiplier = tier;
        gpuMetadata = new string("GPU: CUDA");
        cout << "GPUAcceleratedServer constructor called" << endl;
    }
    ~GPUAcceleratedServer() {
        delete gpuMetadata;
        cout << "GPUAcceleratedServer destructor called" << endl;
    }
    double calculateCost(double hours) {
        double serverCost = ServerInstance::calculateCost(hours);
        double gpuFee = gpuCount * gpuModelTierMultiplier * 0.50 * hours;
        return serverCost + gpuFee;
    }
};
int main() {
    {
        GPUAcceleratedServer server("gpu-node-01", 0.40, 16, 64.0, 4, 2.5);
        cout << "\nCost for 24 hours: $" << server.calculateCost(24) << endl;
        cout << "\nObject is going out of scope..." << endl;
    }
    cout << "Out of scope now." << endl;
    return 0;
}
