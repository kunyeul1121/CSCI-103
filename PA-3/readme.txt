PA-3: It's So Belurry
Readme.txt
Written by Stanley Kim
Email: stanlejk@usc.edu
Student ID Number: 4293519877

	Prelab
		1.  Padding Design:
			The size of the largest padded image needed to handle padding with 
			any kernel size would be 266 x 266. The upper-left pixel of the 
			original image would be placed at the [N/2][N/2] index. The lower-
			right pixel of the original image would be placed at the [255 + 
			(N / 2)][255 + (N / 2)].

		2.  N = 3, sigma = 2

			Raw Kernel:

			0.7788, 0.8825, 0.7788
			0.8825, 1.0000, 0.8825
			0.7788, 0.8825, 0.7788

			Normalized Kernel:

			0.1019, 0.1154, 0.1019
			0.1154, 0.1308, 0.1154
			0.1019, 0.1154, 0.1019

			If we used the raw kernel, all the colors in the image would 
			become very bright because the sum of the values inside the kernel 
			would add up to larger than the amplitude.

	Experimentation
		1.  When sigma and N are increased, the blur effect is strengthened. 
		Increasing sigma makes a bigger change in the individual pixels, 
		whereas increasing N increases the kernel so that affects a larger 
		area each time.

		2.  The sobel filter appears to highlight edges of the same color, and 
		blacken large areas of the same color.

		3.  Blurring an image and then using the un-sharp mask does not give 
		you the original image back due to clamping. When the image is 
		blurred, many of the values fall out of the boundary [0, 255], and are 
		therefore clamped to 0 or 255. Then when the image is unsharpened, the 
		clamped values will not be accurate to the true values, so the original 
		image will not be returned.