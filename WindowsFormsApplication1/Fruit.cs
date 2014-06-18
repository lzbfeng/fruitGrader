using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace WindowsFormsApplication1
{
    class Fruits
    {
        public ArrayList m_list = new ArrayList();
        public Fruits()
        {
            string def="def";
            int counts=int.Parse(Form1.ReadIni("FRUITS", "nCounts", def));
            for (int i = 0; i < counts;i++ )
            {
                Fruit fruit = new Fruit();
                string a;

                a="IndexOfFruit";
                a += string.Format("{0}", i + 1);
                fruit.index=int.Parse(Form1.ReadIni("FRUITS",a,def));

                a = "TypeOfFruit";
                a += string.Format("{0}", i + 1);
                fruit.type = Form1.ReadIni("FRUITS", a, def);

                a = "UnitPrice";
                a += string.Format("{0}", i + 1);
                fruit.unitPrice =float.Parse( Form1.ReadIni("FRUITS", a, def));

                a = "Discount";
                a += string.Format("{0}", i + 1);
                fruit.discount = float.Parse(Form1.ReadIni("FRUITS", a, def));

                m_list.Add(fruit);
            }
        }
    }
    class Fruit
    {
        public string type;
        public int index;
        public float unitPrice;
        public float discount;
        public float weight=3.5f;

        public float totalPrice;
        public float GetTotalPrice()
        {
            totalPrice = unitPrice * weight * discount/10;
            return totalPrice;
        }
    }
}
