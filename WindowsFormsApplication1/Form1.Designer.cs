namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.button_PrintPre = new System.Windows.Forms.Button();
            this.printPreviewDialog = new System.Windows.Forms.PrintPreviewDialog();
            this.fontDialog = new System.Windows.Forms.FontDialog();
            this.button_setFont = new System.Windows.Forms.Button();
            this.groupBox_otherSet = new System.Windows.Forms.GroupBox();
            this.button_setFontColor = new System.Windows.Forms.Button();
            this.colorDialog = new System.Windows.Forms.ColorDialog();
            this.m_FruitReco = new AxFruitRecoLib.AxFruitReco();
            this.button_Reco = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.checkBox_flagBatch = new System.Windows.Forms.CheckBox();
            this.label_flagBatch = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox_numBatch = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_indexFruit = new System.Windows.Forms.TextBox();
            this.textBox_nameFruit = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.checkBox_otherSet = new System.Windows.Forms.CheckBox();
            this.label_showRecoResult = new System.Windows.Forms.Label();
            this.groupBox_otherSet.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.m_FruitReco)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(6, 10);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(187, 47);
            this.button1.TabIndex = 0;
            this.button1.Text = "打印";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button_PrintPre
            // 
            this.button_PrintPre.Location = new System.Drawing.Point(6, 69);
            this.button_PrintPre.Name = "button_PrintPre";
            this.button_PrintPre.Size = new System.Drawing.Size(73, 47);
            this.button_PrintPre.TabIndex = 0;
            this.button_PrintPre.Text = "打印预览";
            this.button_PrintPre.UseVisualStyleBackColor = true;
            this.button_PrintPre.Click += new System.EventHandler(this.打印预览);
            // 
            // printPreviewDialog
            // 
            this.printPreviewDialog.AutoScrollMargin = new System.Drawing.Size(0, 0);
            this.printPreviewDialog.AutoScrollMinSize = new System.Drawing.Size(0, 0);
            this.printPreviewDialog.ClientSize = new System.Drawing.Size(400, 300);
            this.printPreviewDialog.Enabled = true;
            this.printPreviewDialog.Icon = ((System.Drawing.Icon)(resources.GetObject("printPreviewDialog.Icon")));
            this.printPreviewDialog.Name = "printPreviewDialog";
            this.printPreviewDialog.Visible = false;
            // 
            // button_setFont
            // 
            this.button_setFont.Location = new System.Drawing.Point(6, 20);
            this.button_setFont.Name = "button_setFont";
            this.button_setFont.Size = new System.Drawing.Size(187, 40);
            this.button_setFont.TabIndex = 1;
            this.button_setFont.Text = "设置字体";
            this.button_setFont.UseVisualStyleBackColor = true;
            this.button_setFont.Click += new System.EventHandler(this.button_setFont_Click);
            // 
            // groupBox_otherSet
            // 
            this.groupBox_otherSet.Controls.Add(this.button_setFontColor);
            this.groupBox_otherSet.Controls.Add(this.button_setFont);
            this.groupBox_otherSet.Location = new System.Drawing.Point(658, 411);
            this.groupBox_otherSet.Name = "groupBox_otherSet";
            this.groupBox_otherSet.Size = new System.Drawing.Size(199, 116);
            this.groupBox_otherSet.TabIndex = 2;
            this.groupBox_otherSet.TabStop = false;
            this.groupBox_otherSet.Text = "其它设置";
            this.groupBox_otherSet.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // button_setFontColor
            // 
            this.button_setFontColor.Location = new System.Drawing.Point(6, 66);
            this.button_setFontColor.Name = "button_setFontColor";
            this.button_setFontColor.Size = new System.Drawing.Size(187, 40);
            this.button_setFontColor.TabIndex = 1;
            this.button_setFontColor.Text = "设置字体颜色";
            this.button_setFontColor.UseVisualStyleBackColor = true;
            this.button_setFontColor.Click += new System.EventHandler(this.button_setColor_Click);
            // 
            // m_FruitReco
            // 
            this.m_FruitReco.Enabled = true;
            this.m_FruitReco.Location = new System.Drawing.Point(12, 12);
            this.m_FruitReco.Name = "m_FruitReco";
            this.m_FruitReco.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("m_FruitReco.OcxState")));
            this.m_FruitReco.Size = new System.Drawing.Size(640, 480);
            this.m_FruitReco.TabIndex = 3;
            // 
            // button_Reco
            // 
            this.button_Reco.Location = new System.Drawing.Point(664, 228);
            this.button_Reco.Name = "button_Reco";
            this.button_Reco.Size = new System.Drawing.Size(187, 45);
            this.button_Reco.TabIndex = 4;
            this.button_Reco.Text = "识别";
            this.button_Reco.UseVisualStyleBackColor = true;
            this.button_Reco.Click += new System.EventHandler(this.button_Reco_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.checkBox_flagBatch);
            this.groupBox3.Controls.Add(this.label_flagBatch);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.textBox_numBatch);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.textBox_indexFruit);
            this.groupBox3.Controls.Add(this.textBox_nameFruit);
            this.groupBox3.Controls.Add(this.button2);
            this.groupBox3.Location = new System.Drawing.Point(658, 63);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(199, 158);
            this.groupBox3.TabIndex = 7;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "训练";
            // 
            // checkBox_flagBatch
            // 
            this.checkBox_flagBatch.AutoSize = true;
            this.checkBox_flagBatch.Location = new System.Drawing.Point(121, 32);
            this.checkBox_flagBatch.Name = "checkBox_flagBatch";
            this.checkBox_flagBatch.Size = new System.Drawing.Size(72, 16);
            this.checkBox_flagBatch.TabIndex = 8;
            this.checkBox_flagBatch.Text = "批量训练";
            this.checkBox_flagBatch.UseVisualStyleBackColor = true;
            this.checkBox_flagBatch.CheckedChanged += new System.EventHandler(this.checkBox_flagBatch_CheckedChanged);
            // 
            // label_flagBatch
            // 
            this.label_flagBatch.AutoSize = true;
            this.label_flagBatch.Location = new System.Drawing.Point(119, 66);
            this.label_flagBatch.Name = "label_flagBatch";
            this.label_flagBatch.Size = new System.Drawing.Size(53, 12);
            this.label_flagBatch.TabIndex = 7;
            this.label_flagBatch.Text = "训练数量";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(11, 66);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "水果编号";
            // 
            // textBox_numBatch
            // 
            this.textBox_numBatch.Location = new System.Drawing.Point(121, 81);
            this.textBox_numBatch.Name = "textBox_numBatch";
            this.textBox_numBatch.Size = new System.Drawing.Size(66, 21);
            this.textBox_numBatch.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 7;
            this.label1.Text = "水果名字";
            // 
            // textBox_indexFruit
            // 
            this.textBox_indexFruit.Location = new System.Drawing.Point(13, 81);
            this.textBox_indexFruit.Name = "textBox_indexFruit";
            this.textBox_indexFruit.Size = new System.Drawing.Size(66, 21);
            this.textBox_indexFruit.TabIndex = 6;
            // 
            // textBox_nameFruit
            // 
            this.textBox_nameFruit.Location = new System.Drawing.Point(13, 35);
            this.textBox_nameFruit.Name = "textBox_nameFruit";
            this.textBox_nameFruit.Size = new System.Drawing.Size(66, 21);
            this.textBox_nameFruit.TabIndex = 6;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(6, 108);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(187, 45);
            this.button2.TabIndex = 5;
            this.button2.Text = "训练";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(664, 12);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(188, 45);
            this.button3.TabIndex = 6;
            this.button3.Text = "生成背景";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.checkBox_otherSet);
            this.groupBox2.Controls.Add(this.button1);
            this.groupBox2.Controls.Add(this.button_PrintPre);
            this.groupBox2.Location = new System.Drawing.Point(658, 279);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(199, 126);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "打印";
            // 
            // checkBox_otherSet
            // 
            this.checkBox_otherSet.AutoSize = true;
            this.checkBox_otherSet.Location = new System.Drawing.Point(94, 85);
            this.checkBox_otherSet.Name = "checkBox_otherSet";
            this.checkBox_otherSet.Size = new System.Drawing.Size(72, 16);
            this.checkBox_otherSet.TabIndex = 1;
            this.checkBox_otherSet.Text = "其它设置";
            this.checkBox_otherSet.UseVisualStyleBackColor = true;
            this.checkBox_otherSet.CheckedChanged += new System.EventHandler(this.checkBox_otherSet_CheckedChanged);
            // 
            // label_showRecoResult
            // 
            this.label_showRecoResult.AutoSize = true;
            this.label_showRecoResult.Location = new System.Drawing.Point(10, 508);
            this.label_showRecoResult.Name = "label_showRecoResult";
            this.label_showRecoResult.Size = new System.Drawing.Size(41, 12);
            this.label_showRecoResult.TabIndex = 9;
            this.label_showRecoResult.Text = "label3";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(864, 529);
            this.Controls.Add(this.label_showRecoResult);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.button_Reco);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.m_FruitReco);
            this.Controls.Add(this.groupBox_otherSet);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "水果识别秤";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox_otherSet.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.m_FruitReco)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button_PrintPre;
        private System.Windows.Forms.PrintPreviewDialog printPreviewDialog;
        private System.Windows.Forms.FontDialog fontDialog;
        private System.Windows.Forms.Button button_setFont;
        private System.Windows.Forms.GroupBox groupBox_otherSet;
        private System.Windows.Forms.Button button_setFontColor;
        private System.Windows.Forms.ColorDialog colorDialog;
        private AxFruitRecoLib.AxFruitReco m_FruitReco;
        private System.Windows.Forms.Button button_Reco;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_indexFruit;
        private System.Windows.Forms.TextBox textBox_nameFruit;
        private System.Windows.Forms.CheckBox checkBox_flagBatch;
        private System.Windows.Forms.Label label_flagBatch;
        private System.Windows.Forms.TextBox textBox_numBatch;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox checkBox_otherSet;
        private System.Windows.Forms.Label label_showRecoResult;
    }
}

