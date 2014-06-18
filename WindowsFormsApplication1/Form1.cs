using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Printing;
using System.Threading;
using System.IO.Ports;
using System.Runtime.InteropServices;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        const int paperSizeWidth = 228;
        const int paperSizeHeight = 230;
        const int WM_TRAINED = 0X9876;
        Brush brush_black;
        Brush brush_blue;
        Font font12;
        Font font10_5;
        Font font9;
        Font font16;

        SerialPort m_comPort;

        int index;
        string str_print;
        string str_print_kongke = "   ";
        float str_lenPixel;
        SizeF stringSize;
        Pen pen;
        Font font;
        public static string m_iniPath = System.Environment.CurrentDirectory + @"\Config.ini";
        string m_str_load = "";
        float m_weight = 0;
        string m_recoResult = "苹果";
        Fruits m_fruits = new Fruits();
        Fruit m_recoFruit = new Fruit();
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string section, string key, string def, StringBuilder retVal, int size, string filePath);  

        public Form1()
        {
            InitializeComponent();
        }

        #region 打印
        private PrintDocument pd;
        private void InitPrint()
        {
            pd = new PrintDocument();
            //设置边距
            Margins margin = new Margins(0, 40, 0, 0);
            pd.DefaultPageSettings.Margins = margin;
            ////纸张设置默认
            PaperSize pageSize = new PaperSize("First custom size", paperSizeWidth,paperSizeHeight);//一百分之一英寸为单位  1英寸=2.54厘米
            pd.DefaultPageSettings.PaperSize = pageSize;
            //打印事件设置
            pd.PrintPage += new PrintPageEventHandler(this.pd_PrintPage);
        }
        private void button1_Click(object sender, EventArgs e)
        {
            InitPrint();
            try
            {
                pd.Print();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "打印出错", MessageBoxButtons.OK, MessageBoxIcon.Error);
                pd.PrintController.OnEndPrint(pd, new PrintEventArgs());
            }
        }
        //打印事件处理
        private void pd_PrintPage(object sender, PrintPageEventArgs e)
        {
            
            /*MessageBox.Show(payDate);*/
            //读取图片模板
//             Image temp = Image.FromFile(@"C:\Users\Public\Pictures\Sample Pictures\Desert.jpg");
//             //GetResultIntoImage(ref temp,/* UserId, flowId, */payDate/* baseExpense, fine, upExpense, actualExpense, chineseExpense, payDate, adminId*/);
            int x = e.MarginBounds.X;
            int y = e.MarginBounds.Y;
            int width=e.MarginBounds.Width;
            int height=e.MarginBounds.Height;
//             int width = temp.Width;
//             int height = temp.Height;
//             Rectangle destRect = new Rectangle(x, y, width, height);
//             
//             //brush = new SolidBrush(Color.Black);
//             /*g.DrawString("lzb", f1, b1, 50, 50);*/
//             //e.Graphics.DrawImage(temp, destRect, 0, 0, temp.Width, temp.Height, System.Drawing.GraphicsUnit.Pixel);
//             for (int i = 0; i < paperSizeHeight/font12.GetHeight();i++ )
//             {
//                 e.Graphics.DrawString("华文行楷", font12, brush_black, new PointF(0, i*font12.GetHeight()));
//             }

            
            //打印“欢迎您的光临”
            index = 0;
            font = font16;
            str_print = "欢迎您的光临";
            stringSize = e.Graphics.MeasureString(str_print, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_print, font, brush_blue, new Point((width-(int)str_lenPixel)/2, 0));
            index += font.Height;

            //打印横线
            
            pen = new Pen(brush_black);
            e.Graphics.DrawLine(pen, new Point(0, index += 3), new Point(width, index));

            //打印“郑州大学”  
            font = font12;
            str_print = "郑州大学";
            stringSize = e.Graphics.MeasureString(str_print, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_print, font, brush_black, new Point((width - (int)str_lenPixel) / 2, index += 3));
            index += font.Height;

            //打印“基于机器视觉的自动水果秤”
            font = font10_5;
            str_print = "基于机器视觉的自动水果秤";
            stringSize = e.Graphics.MeasureString(str_print, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_print, font, brush_black, new Point((width - (int)str_lenPixel) / 2, index += 3));
            index += font.Height;

            //打印“销售日期”
            font = font9;
            str_print = "销售日期:";
            DateTime date = DateTime.Now;

            string payDate = string.Format("{0:d}/{1:d}/{2:d}", date.Year, date.Month, date.Day);
            str_print += payDate;
            stringSize = e.Graphics.MeasureString(str_print, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_print, font, brush_black, new Point(0, index += 3));
            string t_str_time = string.Format("{0:d}时{1:d}分", date.Hour, date.Minute);
            stringSize = e.Graphics.MeasureString(t_str_time, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(t_str_time, font, brush_black, new Point(width-(int)str_lenPixel-5, index));
            index += font.Height+10;
            
            //打印虚线
            pen = new Pen(brush_black);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDotDot;
            pen.DashPattern = new float[] { 2, 2 };
            e.Graphics.DrawLine(pen,new Point(0,index),new Point(width,index));
            index += 3;

            //打印“类别”
            font = font9;            
            string str_fruitStyle = "类别";
            string str_fruitPrice = "单价";
            string str_fruitWeight = "重量";
            string str_fruitZhekou = "折扣";
            string str_fruitMoney = "金额";
            PrintResult(e, str_fruitStyle, str_fruitPrice, str_fruitWeight, str_fruitZhekou, str_fruitMoney);
            index += font.Height;
            index += 3;

            //打印虚线
            pen = new Pen(brush_black);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDotDot;
            pen.DashPattern = new float[] { 2, 2 };
            e.Graphics.DrawLine(pen, new Point(0, index), new Point(width, index));
            index += 3;

            //打印“水果”
            font = font9;
            str_fruitStyle = m_recoFruit.type;
            str_fruitPrice = string.Format("{0:0.00}", m_recoFruit.unitPrice);
            str_fruitWeight = string.Format("{0:0.00}", m_recoFruit.weight);
            str_fruitZhekou = string.Format("{0:0.00}", m_recoFruit.discount);
            str_fruitMoney = string.Format("{0:0.00}", m_recoFruit.GetTotalPrice());
            PrintResult(e, str_fruitStyle, str_fruitPrice, str_fruitWeight, str_fruitZhekou, str_fruitMoney);
            index += font.Height;

//             font = font9;
//             str_fruitStyle = "橘子";
//             str_fruitPrice = "3.5";
//             str_fruitWeight = "2.1";
//             str_fruitZhekou = "9";
//             str_fruitMoney = "6.6";
//             PrintResult(e, str_fruitStyle, str_fruitPrice, str_fruitWeight, str_fruitZhekou, str_fruitMoney);
//             index += font.Height;
//             index += 3;

            //打印虚线
            pen = new Pen(brush_black);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDotDot;
            pen.DashPattern = new float[] { 2, 2 };
            e.Graphics.DrawLine(pen, new Point(0, index), new Point(width, index));
            index += 3;

            //打印合计
            font = font10_5;
            string str_printHejiWord = "合计：";
            stringSize = e.Graphics.MeasureString(str_printHejiWord, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_printHejiWord, font, brush_black, new Point(5, index += 3));

            string str_printHeji = string.Format("{0:0.00}", m_recoFruit.GetTotalPrice())+"元";
            stringSize = e.Graphics.MeasureString(str_printHeji, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_printHeji, font, brush_black, new Point(width-(int)str_lenPixel, index += 3));
            index += font.Height;

        }
        private void PrintResult(PrintPageEventArgs e,string str_fruitStyle, string str_fruitPrice, 
            string str_fruitWeight, string str_fruitZhekou, string str_fruitMoney,bool flag_left=true)
        {
            int width = e.MarginBounds.Width;
            int height = e.MarginBounds.Height;

            int len_perWord = width / 5;
            int[] len_perWordBianjie = new int[5];
            for (int i = 0; i < 5; i++)
            {
                len_perWordBianjie[i] = flag_left?len_perWord*i:len_perWord * (i + 1);
            }

            font = font9;            

            stringSize = e.Graphics.MeasureString(str_fruitStyle, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_fruitStyle, font, brush_black, new Point(flag_left ? len_perWordBianjie[0] : len_perWordBianjie[0] - (int)str_lenPixel, index));

            stringSize = e.Graphics.MeasureString(str_fruitPrice, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_fruitPrice, font, brush_black, new Point(flag_left ? len_perWordBianjie[1] : len_perWordBianjie[1] - (int)str_lenPixel, index));

            stringSize = e.Graphics.MeasureString(str_fruitWeight, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_fruitWeight, font, brush_black, new Point(flag_left ? len_perWordBianjie[2] : len_perWordBianjie[2] - (int)str_lenPixel, index));

            stringSize = e.Graphics.MeasureString(str_fruitZhekou, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_fruitZhekou, font, brush_black, new Point(flag_left ? len_perWordBianjie[3] : len_perWordBianjie[3] - (int)str_lenPixel, index));

            stringSize = e.Graphics.MeasureString(str_fruitMoney, font);
            str_lenPixel = stringSize.Width;
            e.Graphics.DrawString(str_fruitMoney, font, brush_black, new Point(flag_left ? len_perWordBianjie[4] : len_perWordBianjie[4] - (int)str_lenPixel, index));
        }
        /// <summary>
        /// 将收费结果填充到图片模板
        /// </summary>
        private void GetResultIntoImage(
            ref Image temp,
            string currentDate
            )
        {
            //读取图片模板
            Graphics g = Graphics.FromImage(temp);

            Font f = new Font("宋体", 12);
            Brush b = new SolidBrush(Color.Black);

            //填充数据到图片模板（位置要在制作图片模板的时候度量好）
            //g.DrawImage(temp, 0, 0, temp.Width, temp.Height);
            g.DrawString(currentDate, f, b, 168, 105);
            Font f1=new Font("华文行楷",8);
            Brush b1=new SolidBrush(Color.Red);
            g.DrawString("lzb",f1,b1,50,50);
            g.Dispose();
        }
        #endregion

        private void 打印预览(object sender, EventArgs e)
        {
            this.printPreviewDialog.Document = pd;
            printPreviewDialog.ShowDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            InitPrint();
             
            brush_black = new SolidBrush(Color.Black);
            brush_blue = new SolidBrush(Color.Blue);

            font12 = new Font("宋体", 12);
            font12 = new Font(font12, FontStyle.Bold);

            font9 = new Font("宋体", 9);
            font9 = new Font(font9, FontStyle.Bold);

            font10_5 = new Font("宋体", (float)10.5);
            font10_5 = new Font(font10_5, FontStyle.Bold);

            font16 = new Font("宋体", 16);
            font16 = new Font(font16, FontStyle.Bold);

            m_FruitReco.Init();
            m_FruitReco.OpenCamera();

            checkBox_flagBatch.Checked = false;
            textBox_numBatch.Enabled = false;
            textBox_numBatch.Visible = false;
            label_flagBatch.Visible = false;

            groupBox_otherSet.Visible = false;

            label_showRecoResult.Text = "";

            string def="def";
            string name_comPort = ReadIni("COMPORT","ComPort",def);
            m_str_load = ReadIni("COMPORT", "FlagLoad", def);
            m_comPort = new SerialPort(name_comPort);
            m_comPort.DataReceived += 接收到数据;
            try
            {
                m_comPort.Open();
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
        }

        //读取INI
        public static string ReadIni(string Section, string Ident, string Default)
        {            
            StringBuilder temp = new StringBuilder(255);
            int i = GetPrivateProfileString(Section, Ident, Default, temp, 255, m_iniPath);
            return temp.ToString();           
        }

        private void 接收到数据(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            if (!m_comPort.IsOpen)
            {
                m_comPort.Open();
            }
            string data = m_comPort.ReadLine();
            if (m_str_load==data)
            {
                RecoAndOtherSet();
            }
            try
            {
                m_weight=float.Parse(data);
                m_recoFruit.weight = m_weight;
            }
            catch (System.Exception ex)
            {
                //MessageBox.Show(ex.Message);
            }
        }

        private void button_setFont_Click(object sender, EventArgs e)
        {
            fontDialog.ShowDialog();
            
            font12 = fontDialog.Font;
        }

        private void button_setColor_Click(object sender, EventArgs e)
        {
            colorDialog.ShowDialog();
            brush_black = new SolidBrush(colorDialog.Color);
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button_Reco_Click(object sender, EventArgs e)
        {
            RecoAndOtherSet();
        }
        //识别并且显示出来、发送至下位机等操作
        private void RecoAndOtherSet()
        {
            m_recoResult = m_FruitReco.RecognizeFruit("");

            if (m_recoResult==null||m_recoResult=="")
            {
                MessageBox.Show("未能识别水果！");
                return;
            }
            foreach (Fruit fruit in m_fruits.m_list)
            {
                if (m_recoResult == fruit.type)
                {
                    m_recoFruit = fruit;
                    break;
                }
            }
            string sendData = m_recoResult + "\r\n";
            m_comPort.Write(sendData);
            label_showRecoResult.Text = "已经检测到此水果为：" + m_recoResult;
            MessageBox.Show(m_recoResult);
        }
        private int m_countTrain = -1;
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                if (checkBox_flagBatch.Checked)
                {
                    m_countTrain = int.Parse(textBox_numBatch.Text);
                    int count = int.Parse(textBox_numBatch.Text);
//                     for (int i = 0; i < count;i++ )
//                     {
                        //Thread.Sleep(1000);
                        m_FruitReco.TrainFruit(textBox_nameFruit.Text, (short)int.Parse(textBox_indexFruit.Text), "");
                        m_countTrain--;
//                    }
                }
                else
                {
                    m_FruitReco.TrainFruit(textBox_nameFruit.Text, (short)int.Parse(textBox_indexFruit.Text), "");
                }
                
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            m_FruitReco.CreateBG("");
        }

        private void checkBox_flagBatch_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox_flagBatch.Checked)
            {
                textBox_numBatch.Enabled = true;
                textBox_numBatch.Visible = true;
                label_flagBatch.Visible = true;
            }
            else
            {
                textBox_numBatch.Enabled = false;
                textBox_numBatch.Visible = false;
                label_flagBatch.Visible = false;
            }
        }

        protected override void WndProc(ref System.Windows.Forms.Message msg)
        {
            switch (msg.Msg)
            {
                case WM_TRAINED:
                    if (m_countTrain>0)
                    {
                        //Thread.Sleep(100);
                        m_FruitReco.TrainFruit(textBox_nameFruit.Text, (short)int.Parse(textBox_indexFruit.Text), "");
                        m_countTrain--;
                    }                    
                    break;
                default:
                    base.WndProc(ref msg);//调用基类函数处理非自定义消息。
                    break;
            }

        }

        private void checkBox_otherSet_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox_otherSet.Checked)
            {
                groupBox_otherSet.Visible = true;
            }
            else
            {
                groupBox_otherSet.Visible = false;
            }
        }
    }
}
