#include <iostream>
#include <stdexcept>
#include "SensoreAcqua.h"
#include "SensoreAria.h"
#include "SensoreSuolo.h"
#include "CollezioneSensori.h"
#include "Modello.h"

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
        SensoreAria* clonedSensor = customSensor.clone();
        std::cout << "Cloned sensor name: " << clonedSensor->getNome() << std::endl;
        customSensor.setNome("Nome di prova");
        std::cout << "Custom sensor name: " << customSensor.getNome() << std::endl;
        std::cout << "Cloned sensor name: " << clonedSensor->getNome() << std::endl;
        delete clonedSensor;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void testSensoreSuolo() {
    try {
        // Test constructors
        SensoreSuolo defaultSensor;
        SensoreSuolo customSensor("Sensor1", 95, 1, 15.0, 40.0, 850, 950, 220000, 290000);

        // Test getters
        std::cout << "Nome: " << customSensor.getNome() << std::endl;
        std::cout << "Precisione: " << customSensor.getPrecisione() << std::endl;
        std::cout << "ID: " << customSensor.getID() << std::endl;
        std::cout << "MinValidTemperatura: " << customSensor.getMinValidTemperatura() << std::endl;
        std::cout << "MaxValidTemperatura: " << customSensor.getMaxValidTemperatura() << std::endl;
        std::cout << "MinValidPH: " << customSensor.getMinValidPH() << std::endl;
        std::cout << "MaxValidPH: " << customSensor.getMaxValidPH() << std::endl;
        std::cout << "MinValidUmidità: " << customSensor.getMinValidUmidità() << std::endl;
        std::cout << "MaxValidUmidità: " << customSensor.getMaxValidUmidità() << std::endl;

        // Test setters
        customSensor.setNome("UpdatedSensor1");
        customSensor.setPrecisione(90);
        customSensor.setID(2);
        customSensor.setMinValidTemperatura(20.0);
        customSensor.setMaxValidTemperatura(35.0);
        customSensor.setMinValidPH(900);
        customSensor.setMaxValidPH(925);
        customSensor.setMinValidUmidità(230000);
        customSensor.setMaxValidUmidità(280000);

        // Test temperature methods
        customSensor.addTemperaturaRecord(25.5);
        customSensor.addTemperaturaRecord(30.0);
        customSensor.insertTemperaturaRecord(1, 27.5);
        std::cout << "Temperatura at index 1: " << customSensor.getTemperaturaRecord(1) << std::endl;
        customSensor.updateTemperaturaRecord(1, -28.0);
        customSensor.removeTemperaturaRecord(0);

        // Test PH methods
        customSensor.addPHRecord(910);
        customSensor.addPHRecord(920);
        customSensor.insertPHRecord(1, 915);
        std::cout << "PH at index 1: " << customSensor.getPHRecord(1) << std::endl;
        customSensor.updatePHRecord(1, 1917);
        customSensor.removePHRecord(0);

        // Test Umidità methods
        customSensor.addUmiditàRecord(250000);
        customSensor.addUmiditàRecord(260000);
        customSensor.insertUmiditàRecord(1, 255000);
        std::cout << "Umidità at index 1: " << customSensor.getUmiditàRecord(1) << std::endl;
        customSensor.updateUmiditàRecord(1, 257000);
        customSensor.removeUmiditàRecord(0);

        // Test min/max methods
        std::cout << "Min Temperatura: " << customSensor.MinTemperatura() << std::endl;
        std::cout << "Max Temperatura: " << customSensor.MaxTemperatura() << std::endl;
        std::cout << "Min PH: " << customSensor.MinPH() << std::endl;
        std::cout << "Max PH: " << customSensor.MaxPH() << std::endl;
        std::cout << "Min Umidità: " << customSensor.MinUmidità() << std::endl;
        std::cout << "Max Umidità: " << customSensor.MaxUmidità() << std::endl;

        // Test Qualità method
        std::cout << "Qualità: " << customSensor.Qualità() << "%" << std::endl;

        // Test clone method
        SensoreSuolo* clonedSensor = customSensor.clone();
        std::cout << "Cloned sensor name: " << clonedSensor->getNome() << std::endl;
        customSensor.setNome("Nome di prova");
        std::cout << "Custom sensor name: " << customSensor.getNome() << std::endl;
        std::cout << "Cloned sensor name: " << clonedSensor->getNome() << std::endl;
        customSensor.addTemperaturaRecord(50.2);

        std::cout<<"CustomSensor: "<<std::endl;
        for(int i= 0; i < customSensor.getTemperaturaVector().size(); i++){
            std::cout<<customSensor.getTemperaturaVector().at(i)<<", ";
        }
        std::cout<<"-----------"<<std::endl;

        std::cout<<"ClonedSensor: "<<std::endl;
        for(int i= 0; i < clonedSensor->getTemperaturaVector().size(); i++){
            std::cout<<clonedSensor->getTemperaturaVector().at(i)<<", ";
        }
        std::cout<<"-----------"<<std::endl;

        delete clonedSensor;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void testCollezioneSensori() {
    try {
        CollezioneSensori collezione;

        // Test addSensore
        Sensore* s1 = new SensoreAcqua("Acqua1", 95, 1, 15.0, 40.0, 850, 950, 220000, 290000);
        Sensore* s2 = new SensoreAria("Aria1", 90, 2, 10.0, 35.0, 300, 500, 19, 21);
        Sensore* s3 = s1->clone();
        s3->setNome("Acqua2");
        collezione.addSensore(s1);
        collezione.addSensore(s2);
        collezione.addSensore(s3);

        // Test getSensore and getSize
        std::cout << "Collezione size: " << collezione.getSize() << std::endl;
        std::cout << "Sensore at 0: " << collezione.getSensore(0)->getNome() << std::endl;
        std::cout << "Sensore at 2: " << collezione.getSensore(2)->getNome() << std::endl;

        // Test insertSensore
        Sensore* s4 = new SensoreSuolo("Suolo1", 85, 3, 5.0, 30.0, 6, 8, 20, 80);
        collezione.insertSensore(s4, 1);

std::cout << "Collezione size: " << collezione.getSize() << std::endl;

        // Test removeSensore
        collezione.removeSensore(0);

        std::cout << "Collezione size: " << collezione.getSize() << std::endl;

        // Test isEmpty and clear
        std::cout << "Is empty: " << (collezione.isEmpty() ? "Yes" : "No") << std::endl;
        collezione.clear();
        std::cout << "Is empty after clear: " << (collezione.isEmpty() ? "Yes" : "No") << std::endl;

        // Test setSensore
        collezione.addSensore(new SensoreAcqua("Acqua3", 92, 4, 18.0, 38.0, 860, 940, 230000, 280000));
        collezione.setSensore(0, "UpdatedAcqua", 93, 20.0, 36.0, 870, 930, 240000, 270000);

        // Test copy constructor and assignment operator
        CollezioneSensori collezione2 = collezione;
        CollezioneSensori collezione3;
        collezione3 = collezione;

        std::cout << "Original size: " << collezione.getSize() << std::endl;
        std::cout << "Copied size: " << collezione2.getSize() << std::endl;
        std::cout << "Assigned size: " << collezione3.getSize() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception in CollezioneSensori test: " << e.what() << std::endl;
    }
}

void testModello() {
    try {
        Model modello;

        // Test addNewSensore
        modello.addNewSensore("SensoreAcqua", "Acqua1", 95, 15.0, 40.0, 850, 950, 220000, 290000, 0, 0, 0, 0, 0, 0, 0, 0);
        modello.addNewSensore("SensoreAria", "Aria1", 90, 10.0, 35.0, 0, 0, 0, 0, 19, 21, 300, 500, 0, 0, 0, 0);
        modello.addNewSensore("SensoreSuolo", "Suolo1", 85, 5.0, 30.0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 80, 6, 8);

        // Test getSensore and getSize
        std::cout << "Modello size: " << modello.getSize() << std::endl;
        std::cout << "Sensore at 1: " << modello.getSensore(1)->getNome() << std::endl;

        // Test insertNewSensore
        modello.insertNewSensore("SensoreAcqua", "Acqua2", 92, 18.0, 38.0, 860, 940, 230000, 280000, 0, 0, 0, 0, 0, 0, 0, 0, 1);

        // Test removeSensore
        modello.removeSensore(0);

        // Test setSensore
        modello.setSensore(0, "UpdatedAria", 91, 12.0, 33.0, 0, 0, 0, 0, 18, 22, 320, 480, 0, 0, 0, 0);

        std::cout << "Sensore at 0: " << modello.getSensore(0)->getNome() << std::endl;

        std::cout << "Sensore at 2: " << modello.getSensore(2)->getNome() << std::endl;

        // Test isEmpty and removeSensori
        std::cout << "Is empty: " << (modello.isEmpty() ? "Yes" : "No") << std::endl;
        modello.removeSensori();
        std::cout << "Is empty after removeSensori: " << (modello.isEmpty() ? "Yes" : "No") << std::endl;

        // Test copy constructor and assignment operator
        Model modello2 = modello;
        Model modello3;

        modello.insertNewSensore("SensoreAcqua", "Acqua2", 92, 18.0, 38.0, 860, 940, 230000, 280000, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        modello3 = modello;

        std::cout<<"Modello3 size: "<<modello3.getSize()<<std::endl;

        modello3.insertNewSensore("SensoreAria", "Aria", 92, 18.0, 38.0, 860, 940, 230000, 280000, 0, 0, 0, 0, 0, 0, 0, 0, 1);
        modello3.removeSensore(0);
        modello3.insertNewSensore("SensoreSuolo", "Suolo", 92, 18.0, 38.0, 860, 940, 230000, 280000, 0, 0, 0, 0, 0, 0, 0, 0, 1);


        std::cout << "Original size: " << modello.getSize() << std::endl;
        std::cout << "Copied size: " << modello2.getSize() << std::endl;
        std::cout << "Assigned size: " << modello3.getSize() << std::endl;

        std::cout << "Sensore at 0 modello: " << modello.getSensore(0)->getNome() << std::endl;
        std::cout << "Sensore at 0 modello3: " << modello3.getSensore(0)->getNome() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception in Modello test: " << e.what() << std::endl;
    }
}

void testSensoreCreator() {
    try {
        // Test createSensore for each type
        Sensore* acqua = SensoreCreator::createSensore("SensoreAcqua", 1, "Acqua1", 95, 15.0, 40.0, 850, 950, 220000, 290000, 0, 0, 0, 0, 0, 0, 0, 0);
        Sensore* aria = SensoreCreator::createSensore("SensoreAria", 2, "Aria1", 90, 10.0, 35.0, 0, 0, 0, 0, 19, 21, 300, 500, 0, 0, 0, 0);
        Sensore* suolo = SensoreCreator::createSensore("SensoreSuolo", 3, "Suolo1", 85, 5.0, 30.0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 80, 6, 8);

        std::cout << "Created Acqua sensor: " << acqua->getNome() << std::endl;
        std::cout << "Created Aria sensor: " << aria->getNome() << std::endl;
        std::cout << "Created Suolo sensor: " << suolo->getNome() << std::endl;

        // Test invalid type
        try {
            Sensore* invalid = SensoreCreator::createSensore("SensoreAria", 4, "Valid1", 80, 0.0, 100.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught expected exception for invalid type: " << e.what() << std::endl;
        }

        // Clean up
        delete acqua;
        delete aria;
        delete suolo;

    } catch (const std::exception& e) {
        std::cerr << "Exception in SensoreCreator test: " << e.what() << std::endl;
    }
}

int main() {
    //testSensoreAcqua();
    //testSensoreAria();
    //testSensoreSuolo();
    //testCollezioneSensori();
    //testModello();
    testSensoreCreator();
    return 0;
}
