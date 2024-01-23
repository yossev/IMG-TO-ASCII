# A Simple IMG to ASCII Convertor Using OpenCV
## How Does It Work?
<p>The OpenVC Library Provides the ```cv::Mat``` DataType Which either stores a Multi-channel image ( Colored ) or a Single-Channel image ( GreyScale )
, If you're unfamiliar with how GreyScale Images work here's my main reference while building this project<br />
https://en.wikipedia.org/wiki/Grayscale <br />
The Idea is to Convert Your Multi-Channel Colored Image into a Single-Channel GreyScale Image and Calculate the Average Intensity of each (Scale X Scale) pixels , adn then replacing them with ASCII Characters , Which are appended in the String 
Depending on the Intensity of each pixel ( Higher Contrast ASCII Letters and Lower Contrast ASCII Letters )



</p>
