#include <spdlog/spdlog.h>
#include <pcap.h>

int main(int argc, char* argv[]) {

    pcap_if_t* alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        spdlog::error("Error finding devices: {}", errbuf);
        return 1;
    }

    for (pcap_if_t* dev = alldevs; dev != nullptr; dev = dev->next) {
        spdlog::info("Device: {}", dev->name);
    }

    pcap_freealldevs(alldevs);

    return 0;
}
