	/*
			//case2
			if( i == 0 && (j > 0 && j < copy -> header.width_px))
			{
		  	 	totalb = (copy -> pixels[i][j-1].blue)*( b.filter[i-1][j-1]) + (copy -> pixels[i][j].blue)*(b.filter[i-1][j]) +
						 (copy -> pixels[i][j+1].blue)*( b.filter[i-1][j+1]) + (copy -> pixels[i][j-1].blue)*(b.filter[i][j-1]) +
						 (copy -> pixels[i][j+1].blue)*( b.filter[i][j+1]) + (copy -> pixels[i][j-1].blue)*(b.filter[i+1][j-1]) +
						 (copy -> pixels[i][j].blue)*( b.filter[i+1][j]) + (copy -> pixels[i][j+1].blue)*(b.filter[i+1][j+1]) +
						 (copy -> pixels[i][j].blue)*( b.filter[i][j]);
				
				totalr = (copy -> pixels[i][j-1].red)*( b.filter[i-1][j-1]) + (copy -> pixels[i][j].red)*(b.filter[i-1][j]) +
						 (copy -> pixels[i][j+1].red)*( b.filter[i-1][j+1]) + (copy -> pixels[i][j-1].red)*(b.filter[i][j-1]) +
						 (copy -> pixels[i][j+1].red)*( b.filter[i][j+1]) + (copy -> pixels[i][j-1].red)*(b.filter[i+1][j-1]) +
						 (copy -> pixels[i][j].red)*( b.filter[i+1][j]) + (copy -> pixels[i][j+1].red)*(b.filter[i+1][j+1]) +
						 (copy -> pixels[i][j].red)*( b.filter[i][j]);
				
				totalg = (copy -> pixels[i][j-1].green)*( b.filter[i-1][j-1]) + (copy -> pixels[i][j].green)*(b.filter[i-1][j]) +
						 (copy -> pixels[i][j+1].green)*( b.filter[i-1][j+1]) + (copy -> pixels[i][j-1].green)*(b.filter[i][j-1]) +
						 (copy -> pixels[i][j+1].green)*( b.filter[i][j+1]) + (copy -> pixels[i][j-1].green)*(b.filter[i+1][j-1]) +
						 (copy -> pixels[i][j].green)*( b.filter[i+1][j]) + (copy -> pixels[i][j+1].green)*(b.filter[i+1][j+1]) +
						 (copy -> pixels[i][j].green)*( b.filter[i][j]);
						 
						 copy -> pixels[i][j].blue = totalb/9;
						 copy -> pixels[i][j].red = totalr/9;
						 copy -> pixels[i][j].green = totalg/9;	
			}
			//case3
			if( i ==  copy -> norm_height && (j > 0 && j < copy -> header.width_px))
			{
			 	totalb = (copy -> pixels[i-1][j-1].blue)*( b.filter[i-1][j-1]) + (copy -> pixels[i-1][j].blue)*(b.filter[i-1][j]) +
						 (copy -> pixels[i-1][j+1].blue)*( b.filter[i-1][j+1]) + (copy -> pixels[i][j-1].blue)*(b.filter[i][j-1]) +
						 (copy -> pixels[i][j+1].blue)*( b.filter[i][j+1]) + (copy -> pixels[i+1][j-1].blue)*(b.filter[i+1][j-1]) +
						 (copy -> pixels[i+1][j].blue)*( b.filter[i+1][j]) + (copy -> pixels[i+1][j+1].blue)*(b.filter[i+1][j+1]) +
						 (copy -> pixels[i][j].blue)*( b.filter[i][j]);
				
				totalr = (copy -> pixels[i-1][j-1].red)*( b.filter[i-1][j-1]) + (copy -> pixels[i-1][j].red)*(b.filter[i-1][j]) +
						 (copy -> pixels[i-1][j+1].red)*( b.filter[i-1][j+1]) + (copy -> pixels[i][j-1].red)*(b.filter[i][j-1]) +
						 (copy -> pixels[i][j+1].red)*( b.filter[i][j+1]) + (copy -> pixels[i+1][j-1].red)*(b.filter[i+1][j-1]) +
						 (copy -> pixels[i+1][j].red)*( b.filter[i+1][j]) + (copy -> pixels[i+1][j+1].red)*(b.filter[i+1][j+1]) +
						 (copy -> pixels[i][j].red)*( b.filter[i][j]);
				
				totalg = (copy -> pixels[i-1][j-1].green)*( b.filter[i-1][j-1]) + (copy -> pixels[i-1][j].green)*(b.filter[i-1][j]) +
						 (copy -> pixels[i-1][j+1].green)*( b.filter[i-1][j+1]) + (copy -> pixels[i][j-1].green)*(b.filter[i][j-1]) +
						 (copy -> pixels[i][j+1].green)*( b.filter[i][j+1]) + (copy -> pixels[i+1][j-1].green)*(b.filter[i+1][j-1]) +
						 (copy -> pixels[i+1][j].green)*( b.filter[i+1][j]) + (copy -> pixels[i+1][j+1].green)*(b.filter[i+1][j+1]) +
						 (copy -> pixels[i][j].green)*( b.filter[i][j]);
						 
						 copy -> pixels[i][j].blue = totalb/9;
						 copy -> pixels[i][j].red = totalr/9;
						 copy -> pixels[i][j].green = totalg/9;
