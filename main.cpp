//
//  main.cpp
//  gerarchia
//
//  Created by Federica Bolognini on 09/07/24.
//
#include <string>
#include <vector>

class Sensore{
private:
    std::string Nome;
    int Precisione;
    int ID;
    double MinValidTemperatura;
    double MaxValidTemperatura;
    std::vector <double> Temperatura;
public:
    Sensore(std::string N, int precisione, int Id, double MinValueT, double MaxValueT): Nome(N), Precisione(precisione), ID(Id), MinValidTemperatura(MinValueT), MaxValidTemperatura(MaxValueT) {}
    double MinTemperatura(){
        double minima = Temperatura[0];
        if(Temperatura.empty()){
            throw std::length_error("il vettore delle temperatura è vuoto.");
        } else {
            for (int i = 1; i < Temperatura.size(); ++i) {
                if (Temperatura[i] < minima) {
                    minima = Temperatura[i];
                }
            }
        }
        return minima;
    }
    double MaxTemperatura(){
        double massima = Temperatura[0];
        if(Temperatura.empty()){
            throw std::length_error("il vettore delle temperature è vuoto.");
        } else {
            for (int i = 1; i < Temperatura.size(); ++i) {
                if (Temperatura[i] > massima) {
                    massima = Temperatura[i];
                }
            }
        }
        return massima;
    }
    virtual int Qualità()=0;
    virtual ~Sensore()=default;
};
    
//classe aria
class SensoreAria:public Sensore{
private:
    int MinValidCO2;
    int MaxValidCO2;
    int MinValidOssigeno;
    int MaxValidOssigeno;
    std::vector <int> CO2;
    std::vector <int> Ossigeno;
public:
    SensoreAria(std::string N, int precisione, int Id, double MinValueT,double MaxValueT,int MinValueCO2, int MaxValueCO2, int MinValueOssigeno,int MaxValueOssigeno):Sensore(N,precisione,Id,MinValueT,MaxValueT),MinValidCO2 (MinValueCO2) ,MaxValidCO2 (MaxValueCO2),MinValidOssigeno(MinValueOssigeno), MaxValidOssigeno(MaxValueOssigeno) {}
    int MinCO2(){
        int minima = CO2[0];
        if(CO2.empty()){
            throw std::length_error("il vettore del CO2 è vuoto.");
            } else {
                for (int i = 1; i < CO2.size(); ++i) {
                    if (CO2[i] < minima) {
                        minima = CO2[i];
                    }
                }
            }
            return minima;
        }
        int MaxCO2(){
            int massima = CO2[0];
            if(CO2.empty()){
                throw std::length_error("il vettore del CO2 è vuoto.");
            } else {
                for (int i = 1; i < CO2.size(); ++i) {
                    if (CO2[i] > massima) {
                        massima = CO2[i];
                    }
                }
            }
            return massima;
        }
        int MinOssigeno(){
            int minima = Ossigeno[0];
            if(Ossigeno.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Ossigeno.size(); ++i) {
                    if (Ossigeno[i] < minima) {
                        minima = Ossigeno[i];
                    }
                }
            }
            return minima;
        }
        int MaxOssigeno(){
            int massima = Ossigeno[0];
            if(Ossigeno.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < CO2.size(); ++i) {
                    if (Ossigeno[i] > massima) {
                        massima = Ossigeno[i];
                    }
                }
            }
            return massima;
        }
        //Qualità(){};
};
    
    //classe acqua
    class SensoreAcqua:public Sensore{
    private:
        double MinValidAlcalinità;
        double MaxValidAlcalinità;
        int MinValidAcidità;
        int MaxValidAcidità;
        std::vector <double> Alcalinità;
        std::vector <int> Acidità;
    public:
        SensoreAcqua(std::string N, int precisione, int Id, double MinValueT,double MaxValueT,double MinValueAl, double MaxValueAl,int MinValueAc, int MaxValueAc):Sensore(N,precisione,Id,MinValueT,MaxValueT),MinValidAlcalinità (MinValueAl), MaxValidAlcalinità(MaxValueAl),MinValidAcidità (MinValueAc), MaxValidAcidità(MaxValueAc) {}
        double MinAlcalinità(){
            int minima = Alcalinità[0];
            if(Alcalinità.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Alcalinità.size(); ++i) {
                    if (Alcalinità[i] < minima) {
                        minima = Alcalinità[i];
                    }
                }
            }
            return minima;
        }
        double MaxAlcalinità(){
            int massima = Alcalinità[0];
            if(Alcalinità.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Alcalinità.size(); ++i) {
                    if (Alcalinità[i] > massima) {
                        massima = Alcalinità[i];
                    }
                }
            }
            return massima;
        }
        int MinAcidità(){
            int minima = Acidità[0];
            if(Acidità.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Acidità.size(); ++i) {
                    if (Acidità[i] < minima) {
                        minima = Acidità[i];
                    }
                }
            }
            return minima;
        }
        int MaxAcidità(){
            int massima = Acidità[0];
            if(Acidità.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Acidità.size(); ++i) {
                    if (Acidità[i] > massima) {
                        massima = Acidità[i];
                    }
                }
            }
            return massima;
        }
        //  Qualità(){};
};
    
    
    //classe Suolo
class SensoreSuolo:public Sensore{
private:
    int MinValidPH;
    int MaxValidPH;
    int MinValidUmidità;
    int MaxValidUmidità;
    std::vector <int> PH;
    std::vector <int> Umidità;
public:
    SensoreSuolo(std::string N, int precisione, int Id,double MinValueT,double MaxValueT,int MinValuePH, int MaxValuePH,int MinValueUmidità, int MaxValueUmidità):Sensore(N,precisione,Id,MinValueT,MaxValueT),MinValidPH (MinValuePH), MaxValidPH(MaxValuePH), MinValidUmidità(MinValueUmidità), MaxValidUmidità(MaxValueUmidità) {}
        int MinPH(){
            int minima = PH[0];
            if(PH.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < PH.size(); ++i) {
                    if (PH[i] < minima) {
                        minima = PH[i];
                    }
                }
            }
            return minima;
        }
    int MaxPH(){
        int massima = PH[0];
            if(PH.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < PH.size(); ++i) {
                    if (PH[i] > massima) {
                        massima = PH[i];
                    }
                }
            }
            return massima;
    }
    int MinUmidità(){
    int minima = Umidità[0];
        if(Umidità.empty()){
            throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Umidità.size(); ++i) {
                    if (Umidità[i] < minima) {
                        minima = Umidità[i];
                    }
                }
            }
            return minima;
    }
    int MaxUmidità(){
        int massima = Umidità[0];
            if(Umidità.empty()){
                throw std::length_error("il vettore delle temperature è vuoto.");
            } else {
                for (int i = 1; i < Umidità.size(); ++i) {
                    if (Umidità[i] > massima) {
                        massima = Umidità[i];
                    }
                }
            }
        return massima;
    }
        //  Qualità(){};

// QUI è PASSATO LO SPIRITO DI RANZATO
};
    

