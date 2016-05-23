using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Structures_Simu
{
    public class Caracteristique
    {
        private int id;
        private int min;
        private int max;
        private string nom;
        private string definition;
        private string type;
        private int precision;
        
        //////////////
        //  GETTER  //
        //////////////

        public int getId()
        { return id; }

        public int getMin()
        { return min; }

        public int getMax()
        { return max; }

        public string getNom()
        {  return nom; }

        public string getDefinition()
        { return definition; }

        public string getType()
        { return type; }

        public int getPrecision()
        { return precision; }

        //////////////
        //  SETTER  //
        //////////////

        public void setId(int i)
        { id = i; }

        public void setMin(int m)
        { min = m; }

        public void setMax(int m)
        { max = m; }

        public void setNom(string n)
        { nom = n; }

        public void setDefinition(string d)
        { definition = d; }

        public void setType(string t)
        { type = t; }

        public void setPrecision(int p)
        { precision = p; }
    }
}
