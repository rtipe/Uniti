//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Vector2f.hpp"
#include "Logger.hpp"

namespace Uniti {
    class Box {
    public:
        /** @brief Constructeur de la classe Box prenant un objet JSON comme argument.
            @param const Json::Value &value : Objet JSON pour l'initialisation.
        */
        Box(const Json::Value &value);

        /** @brief Constructeur de la classe Box prenant des coordonnées et des dimensions.
            @param float x : Coordonnée X.
            @param float y : Coordonnée Y.
            @param float width : Largeur.
            @param float height : Hauteur.
        */
        Box(float x, float y, float width, float height);

        /** @brief Retourne la position actuelle de la boîte (lecture seule).
            @return const Vector2f & : Position de la boîte.
        */
        const Vector2f &getPosition() const;

        /** @brief Retourne la position actuelle de la boîte (lecture/écriture).
            @return Vector2f & : Position de la boîte.
        */
        Vector2f &getPosition();

        /** @brief Retourne les dimensions actuelles de la boîte (lecture seule).
            @return const Vector2f & : Dimensions de la boîte.
        */
        const Vector2f &getDimension() const;

        /** @brief Retourne les dimensions actuelles de la boîte (lecture/écriture).
            @return Vector2f & : Dimensions de la boîte.
        */
        Vector2f &getDimension();

        /** @brief Retourne la coordonnée X de la position (lecture seule).
            @return const float : Coordonnée X de la position.
        */
        const float getX() const;

        /** @brief Retourne la coordonnée X de la position (lecture/écriture).
            @return float : Coordonnée X de la position.
        */
        float getX();

        /** @brief Retourne la coordonnée Y de la position (lecture seule).
            @return const float : Coordonnée Y de la position.
        */
        const float getY() const;

        /** @brief Retourne la coordonnée Y de la position (lecture/écriture).
            @return float : Coordonnée Y de la position.
        */
        float getY();

        /** @brief Retourne la largeur de la boîte (lecture seule).
            @return const float : Largeur de la boîte.
        */
        const float getWidth() const;

        /** @brief Retourne la largeur de la boîte (lecture/écriture).
            @return float : Largeur de la boîte.
        */
        float getWidth();

        /** @brief Retourne la hauteur de la boîte (lecture seule).
            @return const float : Hauteur de la boîte.
        */
        const float getHeight() const;

        /** @brief Retourne la hauteur de la boîte (lecture/écriture).
            @return float : Hauteur de la boîte.
        */
        float getHeight();

        /** @brief Définit la position de la boîte en fonction d'un objet Vector2f donné.
            @param const Vector2f &position : Nouvelle position de la boîte.
        */
        void setPosition(const Vector2f &position);

        /** @brief Définit les dimensions de la boîte en fonction d'un objet Vector2f donné.
            @param const Vector2f &dimension : Nouvelles dimensions de la boîte.
        */
        void setDimension(const Vector2f &dimension);

        /** @brief Définit la coordonnée X de la position de la boîte.
            @param float x : Nouvelle coordonnée X.
        */
        void setX(float x);

        /** @brief Définit la coordonnée Y de la position de la boîte.
            @param float y : Nouvelle coordonnée Y.
        */
        void setY(float y);

        /** @brief Définit la largeur de la boîte.
            @param float width : Nouvelle largeur.
        */
        void setWidth(float width);

        /** @brief Définit la hauteur de la boîte.
            @param float height : Nouvelle hauteur.
        */
        void setHeight(float height);

        /** @brief Vérifie si un point donné est à l'intérieur de la boîte.
            @param const Vector2f &point : Point à vérifier.
            @return bool : Vrai si le point est à l'intérieur de la boîte, sinon faux.
        */
        bool isInside(const Vector2f &point) const;

        /** @brief Vérifie si un point donné est à l'intérieur de la boîte, par rapport à un parent.
            @param const Vector2f &point : Point à vérifier.
            @param const Vector2f &parent : Parent de référence.
            @return bool : Vrai si le point est à l'intérieur de la boîte, sinon faux.
        */
        bool isInside(const Vector2f &point, const Vector2f &parent) const;

        /** @brief Vérifie si une autre boîte est entièrement à l'intérieur de cette boîte.
            @param const Box &box : Boîte à vérifier.
            @return bool : Vrai si l'autre boîte est entièrement à l'intérieur, sinon faux.
        */
        bool isInside(const Box &box) const;

        /** @brief Vérifie si une autre boîte est entièrement à l'intérieur de cette boîte, par rapport à deux parents.
            @param const Box &box : Boîte à vérifier.
            @param const Vector2f &parentA : Premier parent de référence.
            @param const Vector2f &parentB : Deuxième parent de référence.
            @return bool : Vrai si l'autre boîte est entièrement à l'intérieur, sinon faux.
        */
        bool isInside(const Box &box, const Vector2f &parentA, const Vector2f &parentB) const;

    private:
        Vector2f _position;
        Vector2f _dimension;
    };
}

/** @brief Surcharge de l'opérateur de sortie pour afficher la boîte dans un flux de sortie standard.
    @param std::ostream& os : Flux de sortie.
    @param const Uniti::Box &box : Boîte à afficher.
    @return std::ostream& : Référence au flux de sortie.
*/
std::ostream& operator<<(std::ostream& os, const Uniti::Box &box);

/** @brief Surcharge de l'opérateur de sortie pour afficher la boîte dans un objet de journalisation spécifique (Logger).
    @param Uniti::Logger& os : Objet de journalisation.
    @param const Uniti::Box &box : Boîte à afficher.
    @return Uniti::Logger& : Référence à l'objet de journalisation.
*/
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Box &box);
