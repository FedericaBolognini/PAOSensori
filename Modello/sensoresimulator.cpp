#include "sensoresimulator.h"

void SensoreSimulator::simulazioneSensore(Sensore *sensore)
{
    if(sensore){

        unsigned int size = sensore->getTemperaturaVector().size();
        for(unsigned int i=0; i<size;i++){
            sensore->removeTemperaturaRecord(0);
        }

        double range = sensore->getMaxValidTemperatura() - sensore->getMinValidTemperatura();
        double deviation = range * (sensore->getPrecisione() / 100.0);

        std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_real_distribution<double> distTemp(sensore->getMinValidTemperatura() - deviation, sensore->getMaxValidTemperatura() + deviation);

        for (int i = 0; i < 100; ++i) {
            sensore->addTemperaturaRecord(distTemp(rng));
        }

        SensoreAcqua* sensoreAcqua = dynamic_cast<SensoreAcqua*>(sensore);
        SensoreAria* sensoreAria = dynamic_cast<SensoreAria*>(sensore);
        SensoreSuolo* sensoreSuolo = dynamic_cast<SensoreSuolo*>(sensore);

        if(sensoreAcqua){
            size = sensoreAcqua->getAciditàVector().size();
            for(unsigned int i=0; i<size;i++){
                sensoreAcqua->removeAciditàRecord(0);
            }

            size = sensoreAcqua->getAlcalinitàVector().size();
            for(unsigned int i=0; i<size;i++){
                sensoreAcqua->removeAlcalinitàRecord(0);
            }


            range = sensoreAcqua->getMaxValidAcidità() - sensoreAcqua->getMinValidAcidità();
            deviation = range * (sensoreAcqua->getPrecisione() / 100.0);

            std::uniform_real_distribution<double> distAcidità(sensoreAcqua->getMinValidAcidità() - deviation, sensoreAcqua->getMaxValidAcidità() + deviation);

            for (int i = 0; i < 100; ++i) {
                sensoreAcqua->addAciditàRecord(distAcidità(rng));
            }

            range = sensoreAcqua->getMaxValidAlcalinità() - sensoreAcqua->getMinValidAlcalinità();
            deviation = range * (sensoreAcqua->getPrecisione() / 100.0);

            std::uniform_real_distribution<double> distAlcalinità(sensoreAcqua->getMinValidAlcalinità() - deviation, sensoreAcqua->getMaxValidAlcalinità() + deviation);

            for (int i = 0; i < 100; i++) {
                sensoreAcqua->addAlcalinitàRecord(distAlcalinità(rng));
            }
        }

        if(sensoreAria){
            size = sensoreAria->getCO2Vector().size();
            for(unsigned int i=0; i<size;i++){
                sensoreAria->removeCO2Record(0);
            }

            size = sensoreAria->getOssigenoVector().size();
            for(unsigned int i=0; i<size;i++){
                sensoreAria->removeOssigenoRecord(0);
            }


            range = sensoreAria->getMaxValidCO2() - sensoreAria->getMinValidCO2();
            deviation = range * (sensoreAria->getPrecisione() / 100.0);

            std::uniform_real_distribution<double> distCO2(sensoreAria->getMinValidCO2() - deviation, sensoreAria->getMaxValidCO2() + deviation);

            for (int i = 0; i < 100; ++i) {
                sensoreAria->addCO2Record(distCO2(rng));
            }

            range = sensoreAria->getMaxValidOssigeno() - sensoreAria->getMinValidOssigeno();
            deviation = range * (sensoreAria->getPrecisione() / 100.0);

            std::uniform_real_distribution<double> distO2(sensoreAria->getMinValidOssigeno() - deviation, sensoreAria->getMaxValidCO2() + deviation);

            for (int i = 0; i < 100; ++i) {
                sensoreAria->addOssigenoRecord(distO2(rng));
            }
        }

        if(sensoreSuolo){

            size = sensoreSuolo->getPHVector().size();
            for(unsigned int i=0; i<size;i++){
                sensoreSuolo->removePHRecord(0);
            }

            size = sensoreSuolo->getUmiditàVector().size();
            for(unsigned int i=0; i<size;i++){
                sensoreSuolo->removeUmiditàRecord(0);
            }

            range = sensoreSuolo->getMaxValidPH() - sensoreSuolo->getMinValidPH();
            deviation = range * (sensoreSuolo->getPrecisione() / 100.0);

            std::uniform_real_distribution<double> distPH(sensoreSuolo->getMinValidPH() - deviation, sensoreSuolo->getMaxValidPH() + deviation);

            for (int i = 0; i < 100; ++i) {
                sensoreSuolo->addPHRecord(distPH(rng));
            }

            range = sensoreSuolo->getMaxValidUmidità() - sensoreSuolo->getMinValidUmidità();
            deviation = range * (sensoreSuolo->getPrecisione() / 100.0);

            std::uniform_real_distribution<double> distUmidità(sensoreSuolo->getMinValidUmidità() - deviation, sensoreSuolo->getMaxValidUmidità() + deviation);

            for (int i = 0; i < 100; ++i) {
                sensoreSuolo->addUmiditàRecord(distUmidità(rng));
            }
        }
    } else {
        throw(std::runtime_error("Tentativo di simulazione su un sensore non esistente!"));
    }
}
