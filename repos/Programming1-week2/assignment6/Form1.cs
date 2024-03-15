namespace assignment6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string input = textBox1.Text;
            int second = int.Parse(input);
            int minute = (second / 60);
            second = (second % 60);
            int hour = (minute / 60);
            minute = (minute % 60);

            label3.Text = string.Format("{0:00}:{1:00}:{2:00}", hour, minute, second);
        }
    }
}