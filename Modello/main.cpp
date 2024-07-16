#include <iostream>
#include <stdexcept>
#include "SensoreAcqua.h"

void testSensoreAcqua() {
    try {
        // Test constructors
        SensoreAcqua defaultSensor;
        SensoreAcqua customSensor("Sensor1", 95, 1, 15.0, 40.0, 850, 950, 220000, 290000);

        // Test getters
        std::cout << "Nome: " << customSensor.getNome() << std::endl;
        std::cout << "Precisione: " << customSensor.getPrecisione() << std::endl;
        std::cout << "ID: " << customSensor.getID() << std::endl;
        std::cout << "MinValidTemperatura: " << customSensor.getMinValidTemperatura() << std::endl;
        std::cout << "MaxValidTemperatura: " << customSensor.getMaxValidTemperatura() << std::endl;
        std::cout << "MinValidAlcalinità: " << customSensor.getMinValidAlcalinità() << std::endl;
        std::cout << "MaxValidAlcalinità: " << customSensor.getMaxValidAlcalinità() << std::endl;
        std::cout << "MinValidAcidità: " << customSensor.getMinValidAcidità() << std::endl;
        std::cout << "MaxValidAcidità: " << customSensor.getMaxValidAcidità() << std::endl;

        // Test setters
        customSensor.setNome("UpdatedSensor1");
        customSensor.setPrecisione(90);
        customSensor.setID(2);
        customSensor.setMinValidTemperatura(20.0);
        customSensor.setMaxValidTemperatura(35.0);
        customSensor.setMinValidAlcalinità(900);
        customSensor.setMaxValidAlcalinità(925);
        customSensor.setMinValidAcidità(230000);
        customSensor.setMaxValidAcidità(280000);

        // Test temperature methods
        customSensor.addTemperaturaRecord(25.5);
        customSensor.addTemperaturaRecord(30.0);
        customSensor.insertTemperaturaRecord(1, 27.5);
        std::cout << "Temperatura at index 1: " << customSensor.getTemperaturaRecord(1) << std::endl;
        customSensor.updateTemperaturaRecord(1, -28.0);
        customSensor.removeTemperaturaRecord(0);

        // Test alcalinità methods
        customSensor.addAlcalinitàRecord(910);
        customSensor.addAlcalinitàRecord(920);
        customSensor.insertAlcalinitàRecord(1, 915);
        std::cout << "Alcalinità at index 1: " << customSensor.getAlcalinitàRecord(1) << std::endl;
        customSensor.updateAlcalinitàRecord(1, 1917);
        customSensor.removeAlcalinitàRecord(0);

        // Test acidità methods
        customSensor.addAciditàRecord(250000);
        customSensor.addAciditàRecord(260000);
        customSensor.insertAciditàRecord(1, 255000);
        std::cout << "Acidità at index 1: " << customSensor.getAciditàRecord(1) << std::endl;
        customSensor.updateAciditàRecord(1, 257000);
        customSensor.removeAciditàRecord(0);

        // Test min/max methods
        std::cout << "Min Temperatura: " << customSensor.MinTemperatura() << std::endl;
        std::cout << "Max Temperatura: " << customSensor.MaxTemperatura() << std::endl;
        std::cout << "Min Alcalinità: " << customSensor.MinAlcalinità() << std::endl;
        std::cout << "Max Alcalinità: " << customSensor.MaxAlcalinità() << std::endl;
        std::cout << "Min Acidità: " << customSensor.MinAcidità() << std::endl;
        std::cout << "Max Acidità: " << customSensor.MaxAcidità() << std::endl;

        // Test Qualità method
        std::cout << "Qualità: " << customSensor.Qualità() << "%" << std::endl;

        // Test clone method
        SensoreAcqua* clonedSensor = customSensor.clone();
        std::cout << "Cloned sensor name: " << clonedSensor->getNome() << std::endl;
        delete clonedSensor;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
void testSensoreAria() {
    try {
        // Test constructors
        SensoreAria defaultSensor;
        SensoreAria customSensor("Sensor1", 95, 1, 15.0, 40.0, 850, 950, 220000, 290000);

        // Test getters
        std::cout << "Nome: " << customSensor.getNome() << std::endl;
        std::cout << "Precisione: " << customSensor.getPrecisione() << std::endl;
        std::cout << "ID: " << customSensor.getID() << std::endl;
        std::cout << "MinValidTemperatura: " << customSensor.getMinValidTemperatura() << std::endl;
        std::cout << "MaxValidTemperatura: " << customSensor.getMaxValidTemperatura() << std::endl;
        std::cout << "MinValidCO2: " << customSensor.getMinValidCO2() << std::endl;
        std::cout << "MaxValidCO2: " << customSensor.getMaxValidCO2() << std::endl;
        std::cout << "MinValidOssigeno: " << customSensor.getMinValidOssigeno() << std::endl;
        std::cout << "MaxValidOssigeno: " << customSensor.getMaxValidOssigeno() << std::endl;

        // Test setters
        customSensor.setNome("UpdatedSensor1");
        customSensor.setPrecisione(90);
        customSensor.setID(2);
        customSensor.setMinValidTemperatura(20.0);
        customSensor.setMaxValidTemperatura(35.0);
        customSensor.setMinValidCO2(900);
        customSensor.setMaxValidCO2(925);
        customSensor.setMinValidOssigeno(230000);
        customSensor.setMaxValidOssigeno(280000);

        // Test temperature methods
        customSensor.addTemperaturaRecord(25.5);
        customSensor.addTemperaturaRecord(30.0);
        customSensor.insertTemperaturaRecord(1, 27.5);
        std::cout << "Temperatura at index 1: " << customSensor.getTemperaturaRecord(1) << std::endl;
        customSensor.updateTemperaturaRecord(1, -28.0);
        customSensor.removeTemperaturaRecord(0);

        // Test CO2 methods
        customSensor.addCO2Record(910);
        customSensor.addCO2Record(920);
        customSensor.insertCO2Record(1, 915);
        std::cout << "CO2 at index 1: " << customSensor.getCO2Record(1) << std::endl;
        customSensor.updateCO2Record(1, 1917);
        customSensor.removeCO2Record(0);

        // Test Ossigeno methods
        customSensor.addOssigenoRecord(250000);
        customSensor.addOssigenoRecord(260000);
        customSensor.insertOssigenoRecord(1, 255000);
        std::cout << "Ossigeno at index 1: " << customSensor.getOssigenoRecord(1) << std::endl;
        customSensor.updateOssigenoRecord(1, 257000);
        customSensor.removeOssigenoRecord(0);

        // Test min/max methods
        std::cout << "Min Temperatura: " << customSensor.MinTemperatura() << std::endl;
        std::cout << "Max Temperatura: " << customSensor.MaxTemperatura() << std::endl;
        std::cout << "Min CO2: " << customSensor.MinCO2() << std::endl;
        std::cout << "Max CO2: " << customSensor.MaxCO2() << std::endl;
        std::cout << "Min Ossigeno: " << customSensor.MinOssigeno() << std::endl;
        std::cout << "Max Ossigeno: " << customSensor.MaxOssigeno() << std::endl;

        // Test Qualità method
        std::cout << "Qualità: " << customSensor.Qualità() << "%" << std::endl;

        // Test clone method
        SensoreAcqua* clonedSensor = customSensor.clone();
        std::cout << "Cloned sensor name: " << clonedSensor->getNome() << std::endl;
        delete clonedSensor;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}


int main() {
    testSensoreAcqua();
    testSensoreAria();
    return 0;
}
