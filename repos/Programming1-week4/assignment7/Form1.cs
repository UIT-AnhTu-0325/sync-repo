namespace assignment7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int side = int.Parse(textBox1.Text);
            string result = string.Empty;
            for (int i = 0; i < side; i++)
            {
                for (int j = 0; j < side; j++)
                {
                    if (i == 0 || i == side - 1)
                    {
                        result += "x";
                    }
                    else
                    {
                        if (j == 0 || j == side - 1)
                        {
                            result += "x";
                        }
                        else
                        {
                            result += " ";
                        }
                    }
                }
                result += "\n";
            }
            label2.Text = result;
        }
    }
}