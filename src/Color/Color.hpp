//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Logger.hpp"

namespace Uniti {
    class Color {
    public:
        /** @brief Constructeur par défaut de la classe Color.
        */
        Color();

        /** @brief Constructeur de la classe Color prenant un objet JSON comme argument.
            @param const Json::Value &value : Objet JSON pour l'initialisation.
        */
        Color(const Json::Value &value);

        /** @brief Constructeur de copie de la classe Color.
            @param const Color &color : Color à copier.
        */
        Color(const Color &color);

        /** @brief Constructeur de la classe Color prenant les composantes RVB.
            @param int r : Composante rouge.
            @param int g : Composante verte.
            @param int b : Composante bleue.
        */
        Color(int r, int g, int b);

        /** @brief Constructeur de la classe Color prenant les composantes RVBA.
            @param int r : Composante rouge.
            @param int g : Composante verte.
            @param int b : Composante bleue.
            @param int a : Composante alpha (transparence).
        */
        Color(int r, int g, int b, int a);

        /** @brief Retourne la composante rouge de la couleur (lecture seule).
            @return int : Composante rouge.
        */
        int getR() const;

        /** @brief Retourne la composante rouge de la couleur (lecture/écriture).
            @return int & : Composante rouge.
        */
        int &getR();

        /** @brief Retourne la composante verte de la couleur (lecture seule).
            @return int : Composante verte.
        */
        int getG() const;

        /** @brief Retourne la composante verte de la couleur (lecture/écriture).
            @return int & : Composante verte.
        */
        int &getG();

        /** @brief Retourne la composante bleue de la couleur (lecture seule).
            @return int : Composante bleue.
        */
        int getB() const;

        /** @brief Retourne la composante bleue de la couleur (lecture/écriture).
            @return int & : Composante bleue.
        */
        int &getB();

        /** @brief Retourne la composante alpha (transparence) de la couleur (lecture seule).
            @return int : Composante alpha.
        */
        int getA() const;

        /** @brief Retourne la composante alpha (transparence) de la couleur (lecture/écriture).
            @return int & : Composante alpha.
        */
        int &getA();

        /** @brief Définit la composante rouge de la couleur.
            @param int value : Nouvelle valeur de la composante rouge.
        */
        void setR(int value);

        /** @brief Définit la composante verte de la couleur.
            @param int value : Nouvelle valeur de la composante verte.
        */
        void setG(int value);

        /** @brief Définit la composante bleue de la couleur.
            @param int value : Nouvelle valeur de la composante bleue.
        */
        void setB(int value);

        /** @brief Définit la composante alpha (transparence) de la couleur.
            @param int value : Nouvelle valeur de la composante alpha.
        */
        void setA(int value);

        /** @brief Définit les composantes RVB de la couleur.
            @param int r : Composante rouge.
            @param int g : Composante verte.
            @param int b : Composante bleue.
        */
        void set(int r, int g, int b);

        /** @brief Définit les composantes RVBA de la couleur.
            @param int r : Composante rouge.
            @param int g : Composante verte.
            @param int b : Composante bleue.
            @param int a : Composante alpha (transparence).
        */
        void set(int r, int g, int b, int a);

    private:
        int _r;
        int _g;
        int _b;
        int _a;
    };
}

/** @brief Surcharge de l'opérateur de sortie pour afficher la couleur dans un flux de sortie standard.
    @param std::ostream& os : Flux de sortie.
    @param const Uniti::Color &color : Couleur à afficher.
    @return std::ostream& : Référence au flux de sortie.
*/
std::ostream &operator<<(std::ostream &os, const Uniti::Color &color);

/** @brief Surcharge de l'opérateur de sortie pour afficher la couleur dans un objet de journalisation spécifique (Logger).
    @param Uniti::Logger& os : Objet de journalisation.
    @param const Uniti::Color &color : Couleur à afficher.
    @return Uniti::Logger& : Référence à l'objet de journalisation.
*/
Uniti::Logger &operator<<(Uniti::Logger &os, const Uniti::Color &color);
