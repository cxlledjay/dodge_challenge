


int temp_steps = 0;
unsigned int temp_speed = 10;
unsigned int temp_time = 10;

void calculate_animation()
{
	
	if(temp_time == 0)
	{
		//tracking		
		temp_steps = temp_steps + 1;
		if(temp_steps == 3) temp_steps = 0;
		//and reset
		temp_time = temp_speed;
	}
	else
	{
		temp_time = temp_time - 1;
	}
}
