using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

public enum TYPE
{
    ID_AGENT,
    ID_ANIMAL,
    ID_BUILDING,
    ID_RESSOURCE
};

namespace Structures_Simu
{
    ////////////
    // ENTITE //
    ////////////

    public class Entite
    {
        private int nb_id;
        private int id;
        private TYPE typeId;
        private string nom;
        private Dictionary<Objet, int> inventaire;
        private Position pos;
        private bool modif;

        public Entite()
        { }

        public Entite(string s, TYPE tid)
        {
            nb_id = 0;
            typeId = tid;
            nom = s;
            pos.setX(0);
            pos.setY(0);
        }

        ////////////
        // GETTER //
        ////////////

        public int getNbId()
        { return nb_id; }

        public int getId()
        { return id; }

        public string getNom()
        { return nom; }

        public Position getPos()
        { return pos; }

        public bool getModif()
        { return modif; }

        Dictionary<Objet, int> getInventaire()
        { return inventaire; }

        public TYPE getTypeId()
        { return typeId; }

        ////////////
        // SETTER //
        ////////////

        public void incremente_nb_id()
        { nb_id++; }

        public void setId(int i)
        { id = i; }

        public void setModif(bool m)
        { modif = m; }

        public void setNom(string n)
        { nom = n; }

        public void setPos(int x, int y)
        {
            pos.setX(x);
            pos.setY(y);
        }

        public void setInventaire(Dictionary<Objet, int> inv)
        { inventaire = inv; }

    }

    //////////////
    // POSITION //
    ////////////// 

    public class Position
    {
        private int x;
        private int y;

        Position()
        {
            x = 0;
            y = 0;
        }

        public Position(int new_x, int new_y)
        {
            x = new_x;
            y = new_y;
        }

        public bool isInCircle(Position p, int rayon)
        {
            double dist = Math.Sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
            if (dist < rayon)
                return true;
            return false;
        }

        ////////////
        // GETTER //
        ////////////

        public int getX()
        { return x; }

        public int getY()
        { return y; }

        ////////////
        // SETTER //
        ////////////

        public void setX(int i)
        { x = i; }

        public void setY(int i)
        { y = i; }

    }

    ///////////
    // OBJET //
    ///////////

    public class Objet
    {
        private int id;
        private string nom;
        private float taille;

        public Objet(int i, string s, float f)
        {
            id = i;
            nom = s;
            taille = f;
        }

        ////////////
        // GETTER //
        ////////////

        public int getID()
        { return id; }

        public string getNom()
        { return nom; }

        public float getTaille()
        { return taille; }

        ////////////
        // SETTER //
        ////////////

        public void setID(int i)
        { id = i; }

        public void getNom(string n)
        { nom = n; }

        public void getTaille(float t)
        { taille = t; }

    }

}
