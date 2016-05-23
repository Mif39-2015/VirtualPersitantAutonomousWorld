using Structures_Simu;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Structures_Simu
{
    public class Tangible
    {
        private Entite entite;

        public Tangible(string s, TYPE t)
        {
            Entite e = new Entite(s, t);
            entite = e;
        }

        ////////////
        // GETTER //
        ////////////

        public Entite getEntite()
        { return entite; }

    }

    public class Intangible
    {
        private Entite entite;

        public Intangible(string s, TYPE t)
        {
            Entite e = new Entite(s, t);
            entite = e;
        }
    }
}
