#ifndef TRAJET_H
#define TRAJET_H
#include <QtGui>


class Trajet
{
private:
    QStringList m_lstTemp;
    QStringList m_lstAction;
    QStringList m_lstTempInv;
    QStringList m_lstActionInv;

    QString m_non;
    long m_fin;
    long m_debut;
    long m_finInv;
    long m_debutInv;


public:
    Trajet();
    Trajet(QString nom);





        QString getNom();
        void ajouterPoint(long temp,QString action);
        int getNbPoint();
        void setFin(long fin);
        void setDebut(long debut);
        long getFin();
        long getDebut();
        QString getAction(int i);
        long getTempInv(int i);
        QString getActionInv(int i);
        long getTemp(int i);
        void genererInv();
        void clear();

};

/*private String nom;
    private ArrayList lstTemp=new ArrayList();
    private ArrayList lstAction=new ArrayList();
    private ArrayList lstTempInv=new ArrayList();
    private ArrayList lstActionInv=new ArrayList();
    private long fin=0;
    private long debut=0;
    private long finInv=0;
    private long debutInv=0;

    public Trajet(String nom)
    {
        this.nom=nom;

    }

    public String getNom()
    {
        return this.nom;
    }

    public void ajouterPoint(long temp,String action)
    {
        this.lstTemp.add(temp);

        this.lstAction.add(action);
    }

    public int getNbPoint()
    {
        return this.lstTemp.size();
    }



    public void setFin(long fin)
    {
        this.fin=fin;
    }

    public void setDebut(long debut)
    {
        this.debut=debut;
    }

    public long getFin()
    {
        return this.fin;
    }

    public long getDebut()
    {
        return this.debut;
    }

    public String getAction(int i)
    {
        return this.lstAction.get(i).toString();
    }

    public long getTempInv(int i)
    {
        return (long)this.lstTempInv.get(i);
    }

    public String getActionInv(int i)
    {
        return this.lstActionInv.get(i).toString();
    }

    public long getTemp(int i)
    {
        return (long)this.lstTemp.get(i);
    }

    public void afficherToutLesPoints()
    {
        genererInv();


        System.out.println("normale");
        System.out.println("debut = "+this.debut);
        for(int c=0;c<this.lstAction.size();c++)
        {
            System.out.println(this.lstTemp.get(c).toString() +" : "+this.lstAction.get(c).toString());
        }
        System.out.println("fin = "+this.fin);

        System.out.println("inverser");
        System.out.println("debut = "+this.debutInv);
        for(int c=0;c<this.lstActionInv.size();c++)
        {
            System.out.println(this.lstTempInv.get(c).toString() +" : "+this.lstActionInv.get(c).toString());
        }
        System.out.println("fin = "+this.finInv);


    }
    public void clear()
    {
        if(this.getNbPoint()!=0)
        {
            this.lstAction.clear();
            this.lstTemp.clear();
            this.fin=0;
            this.debut=0;
            this.lstActionInv.clear();
            this.lstTempInv.clear();
            this.finInv=0;
            this.debutInv=0;

        }
    }

    public void genererInv()
    {
        this.debutInv=0;
        this.finInv=this.fin;

        for(int c=this.lstAction.size()-1;c>=0;c--)
        {
            this.lstTempInv.add(this.fin-(long)this.lstTemp.get(c));
        }
        for(int c=this.lstAction.size()-1;c>=0;c--)
        {
            //System.out.println("actin a inv = "+ this.lstAction.get(c));
            if(this.lstAction.get(c).toString().compareTo("s")==0)
            {
                if(this.lstAction.get(c-1).toString().compareTo("a")==0)
                    this.lstActionInv.add("r");
                if(this.lstAction.get(c-1).toString().compareTo("r")==0)
                    this.lstActionInv.add("a");
                if(this.lstAction.get(c-1).toString().compareTo("g")==0)
                    this.lstActionInv.add("d");
                if(this.lstAction.get(c-1).toString().compareTo("d")==0)
                    this.lstActionInv.add("g");

            }
            else
                this.lstActionInv.add("s");
        }

    }

*/


#endif // TRAJET_H
