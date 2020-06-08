#include<stdio.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<time.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

struct coordinates
{
	int xCoordinate;
	int yCoordinate;
	int hitcounter;
};

int main() {

	srand(time(NULL));
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_TIMER* timer;

	al_init();
	al_install_keyboard();

	display = al_create_display(600, 800);
	timer = al_create_timer(1.0 / 75);
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	int i;
	int start = 1;
	int knockback = 1;
	int counter = 0;
	int move = 2;
	int direction = 99, directionholder = 99;
	int xpos = 300, ypos = 650;
	int x1pos = 300, y1pos = 620;
	int x2pos = 300, y2pos = 620;
	int hit = 10;
	int directioncounter = 4;
	int score = 0;
	int finish = 0;
	struct coordinates square[10];

	square[0].xCoordinate = rand() % 190 + 10;
	square[0].yCoordinate = 10;
	square[1].xCoordinate = rand() % 300 + 250;
	square[1].yCoordinate = 10;
	square[2].xCoordinate = rand() % 190 + 10;
	square[2].yCoordinate = 70;
	square[3].xCoordinate = rand() % 300 + 250;
	square[3].yCoordinate = 70;
	square[4].xCoordinate = rand() % 190 + 10;
	square[4].yCoordinate = 130;
	square[5].xCoordinate = rand() % 300 + 250;
	square[5].yCoordinate = 130;
	square[6].xCoordinate = rand() % 190 + 10;
	square[6].yCoordinate = 190;
	square[7].xCoordinate = rand() % 300 + 250;
	square[7].yCoordinate = 190;
	square[8].xCoordinate = rand() % 190 + 10;
	square[8].yCoordinate = 250;
	square[9].xCoordinate = rand() % 300 + 250;
	square[9].yCoordinate = 250;

	for (i = 0; i < 10; i++)
	{
		square[i].hitcounter = 10;
	}

	ALLEGRO_FONT* arial = al_load_ttf_font("arial.ttf", 24, 0);
	ALLEGRO_FONT* arial90 = al_load_ttf_font("arial.ttf", 55, 0);
	ALLEGRO_FONT* arial16 = al_load_ttf_font("arial.ttf", 16, 0);

	while (1) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			al_destroy_display(display);
		}


		if (knockback == 1 && finish == 0)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_W)
			{
				knockback = 0;
				counter = 1;
				al_start_timer(timer);
				move = 1;
				if (directioncounter == 4)
				{
					x2pos = 300;
					direction = 3;
					directionholder = direction;
				}
			}
		}

		if (move != 1 && finish == 0)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_D)
			{
				directioncounter++;

				if (directioncounter == 7)
				{
					counter = 0;
					x2pos = 330;
					direction = 10;
					directionholder = direction;
				}
				else if (directioncounter == 10)
				{
					counter = 0;
					x2pos = 360;
					direction = 6;
					directionholder = direction;
				}
				else if (directioncounter == 13)
				{
					counter = 0;
					x2pos = 390;
					direction = 8;
					directionholder = direction;
				}
				else if (directioncounter == -5)
				{
					counter = 0;
					x2pos = 210;
					direction = 9;
					directionholder = direction;
				}
				else if (directioncounter == -2)
				{
					counter = 0;
					x2pos = 240;
					direction = 7;
					directionholder = direction;
				}
				else if (directioncounter == 1)
				{
					counter = 0;
					x2pos = 270;
					direction = 11;
					directionholder = direction;
				}
				else if (directioncounter == 4)
				{
					counter = 0;
					x2pos = 300;
					direction = 3;
					directionholder = direction;
				}

				if (directioncounter >= 13)
				{
					directioncounter = 13;
				}
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_A)
			{
				directioncounter--;
				if (directioncounter == 1)
				{

					counter = 0;
					x2pos = 270;
					direction = 11;
					directionholder = direction;
				}
				else if (directioncounter == -2)
				{

					counter = 0;
					x2pos = 240;
					direction = 7;
					directionholder = direction;
				}
				else if (directioncounter == -5)
				{

					counter = 0;
					x2pos = 210;
					direction = 9;
					directionholder = direction;
				}
				else if (directioncounter == 13)
				{
					counter = 0;
					x2pos = 390;
					direction = 8;
					directionholder = direction;
				}
				else if (directioncounter == 10)
				{
					counter = 0;
					x2pos = 360;
					direction = 6;
					directionholder = direction;
				}
				else if (directioncounter == 7)
				{
					counter = 0;
					x2pos = 330;
					direction = 10;
					directionholder = direction;
				}
				else if (directioncounter == 4)
				{
					counter = 0;
					x2pos = 300;
					direction = 3;
					directionholder = direction;
				}

				if (directioncounter < -5)
				{
					directioncounter = -5;
				}
			}
		}

		if (ypos > 640)
		{
			direction = directionholder;
			counter = 0;
			move = 0;
			knockback = 1;
			ypos = 640;
			al_stop_timer(timer);
		}

		for (i = 0; i < 10; i++)
		{
			if (abs((square[i].xCoordinate + 25) - xpos) <= 45 && abs((square[i].yCoordinate + 25) - ypos) <= 45) //90 derece
			{
				if (direction == 0)
				{
					direction = 1;
					square[i].hitcounter--;
				}
				else if (direction == 1)
				{
					direction = 0;
					square[i].hitcounter--;
				}
				else if (direction == 2)
				{
					direction = 3;
					square[i].hitcounter--;
				}
				else if (direction == 3)
				{
					direction = 2;
					square[i].hitcounter--;
				}
			}

			if (abs((square[i].xCoordinate + 26) - xpos) <= 60 && abs((square[i].yCoordinate + 26) - ypos) <= 40) //yanlar
			{
				if (direction == 4)
				{
					direction = 5;
					square[i].hitcounter--;
				}
				else if (direction == 5)
				{
					direction = 4;
					square[i].hitcounter--;
				}
				else if (direction == 6)
				{
					direction = 7;
					square[i].hitcounter--;
				}
				else if (direction == 7)
				{
					direction = 6;
					square[i].hitcounter--;
				}
				else if (direction == 7)
				{
					direction = 6;
					square[i].hitcounter--;
				}
				else if (direction == 8)
				{
					direction = 9;
					square[i].hitcounter--;
				}
				else if (direction == 10)
				{
					direction = 11;
					square[i].hitcounter--;
				}
				else if (direction == 12)
				{
					direction = 13;
					square[i].hitcounter--;
				}
				else if (direction == 14)
				{
					direction = 15;
					square[i].hitcounter--;
				}
				else if (direction == 9)
				{
					direction = 8;
					square[i].hitcounter--;
				}
				else if (direction == 11)
				{
					direction = 10;
					square[i].hitcounter--;
				}
				else if (direction == 13)
				{
					direction = 12;
					square[i].hitcounter--;
				}
				else if (direction == 15)
				{
					direction = 14;
					square[i].hitcounter--;
				}
			}
			if (abs((square[i].xCoordinate + 26) - xpos) <= 40 && abs((square[i].yCoordinate + 26) - ypos) <= 60) // alt üst
			{
				if (direction == 4)
				{
					direction = 6;
					square[i].hitcounter--;
				}
				else if (direction == 6)
				{
					direction = 4;
					square[i].hitcounter--;
				}
				else if (direction == 5)
				{
					direction = 7;
					square[i].hitcounter--;
				}
				else if (direction == 7)
				{
					direction = 5;
					square[i].hitcounter--;
				}
				else if (direction == 8)
				{
					direction = 12;
					square[i].hitcounter--;
				}
				else if (direction == 9)
				{
					direction = 13;
					square[i].hitcounter--;
				}
				else if (direction == 10)
				{
					direction = 14;
					square[i].hitcounter--;
				}
				else if (direction == 11)
				{
					direction = 15;
					square[i].hitcounter--;
				}
			}
		}


		if (xpos >= 590)
		{
			if (direction == 0)
			{
				direction = 1;
			}
			else if (direction == 4)
			{
				direction = 5;
			}
			else if (direction == 6)
			{
				direction = 7;
			}
			else if (direction == 8)
			{
				direction = 9;
			}
			else if (direction == 10)
			{
				direction = 11;
			}
			else if (direction == 12)
			{
				direction = 13;
			}
			else if (direction == 14)
			{
				direction = 15;
			}
		}
		else if (xpos <= 10)
		{
			if (direction == 1)
			{
				direction = 0;
			}
			else if (direction == 5)
			{
				direction = 4;
			}
			else if (direction == 7)
			{
				direction = 6;
			}
			else if (direction == 9)
			{
				direction = 8;
			}
			else if (direction == 11)
			{
				direction = 10;
			}
			else if (direction == 13)
			{
				direction = 12;
			}
			else if (direction == 15)
			{
				direction = 14;
			}
		}
		else if (ypos <= 20)
		{
			if (direction == 3)
			{
				direction = 2;
			}
			else if (direction == 6)
			{
				direction = 4;
			}
			else if (direction == 7)
			{
				direction = 5;
			}
			else if (direction == 8)
			{
				direction = 12;
			}
			else if (direction == 9)
			{
				direction = 13;
			}
			else if (direction == 10)
			{
				direction = 14;
			}
			else if (direction == 11)
			{
				direction = 15;
			}
		}



		if (direction == 0) //sað
		{
			xpos += 10;
		}
		else if (direction == 1) //sol
		{
			xpos -= 10;
		}
		else if (direction == 2) //asagi
		{
			ypos += 10;
		}
		else if (direction == 3 && counter == 1) //yukari
		{
			ypos -= 10;
		}
		else if (direction == 4) // sag alt
		{
			xpos += 10;
			ypos += 10;
		}
		else if (direction == 5) // sol alt
		{
			xpos -= 10;
			ypos += 10;
		}
		else if (direction == 6 && counter == 1) //sag ust
		{
			xpos += 10;
			ypos -= 10;
		}
		else if (direction == 7 && counter == 1) //sol ust
		{
			xpos -= 10;
			ypos -= 10;
		}
		else if (direction == 8 && counter == 1) //sað sað yukarý
		{
			xpos += 20;
			ypos -= 10;
		}
		else if (direction == 9 && counter == 1) //sol sol yukarý
		{
			xpos -= 20;
			ypos -= 10;
		}
		else if (direction == 10 && counter == 1) //yukarý yukarý sað
		{
			xpos += 10;
			ypos -= 20;
		}
		else if (direction == 11 && counter == 1) //yukarý yukarý sol
		{
			xpos -= 10;
			ypos -= 20;
		}
		else if (direction == 12) // sað sað aþaðý
		{
			xpos += 20;
			ypos += 10;
		}
		else if (direction == 13) // sol sol aþaðý
		{
			xpos -= 20;
			ypos += 10;
		}
		else if (direction == 14) // aþaðý aþaðý sað
		{
			xpos += 10;
			ypos += 20;
		}
		else if (direction == 15) // aþaðý aþaðý sol
		{
			xpos -= 10;
			ypos += 20;
		}

		for (i = 0; i < 10; i++)
		{
			if (square[i].hitcounter <= 0)
			{
				if (i % 2 == 0)
				{
					square[i].xCoordinate = 700;
					square[i].hitcounter = 11;
					score++;
				}
				else if (i % 2 == 1)
				{
					square[i].xCoordinate = 700;
					square[i].hitcounter = 11;
					score++;
				}
			}
		}
		if (square[0].hitcounter == 11 && square[1].hitcounter == 11 && square[2].hitcounter == 11 && square[3].hitcounter == 11 && square[4].hitcounter == 11 && square[5].hitcounter == 11 && square[6].hitcounter == 11 && square[7].hitcounter == 11 && square[8].hitcounter == 11 && square[9].hitcounter == 11 && score < 30)
		{
			if (ypos >= 640)
			{
				square[0].xCoordinate = rand() % 190 + 10;
				square[0].yCoordinate = 10;
				square[1].xCoordinate = rand() % 300 + 250;
				square[1].yCoordinate = 10;
				square[2].xCoordinate = rand() % 190 + 10;
				square[2].yCoordinate = 70;
				square[3].xCoordinate = rand() % 300 + 250;
				square[3].yCoordinate = 70;
				square[4].xCoordinate = rand() % 190 + 10;
				square[4].yCoordinate = 130;
				square[5].xCoordinate = rand() % 300 + 250;
				square[5].yCoordinate = 130;
				square[6].xCoordinate = rand() % 190 + 10;
				square[6].yCoordinate = 190;
				square[7].xCoordinate = rand() % 300 + 250;
				square[7].yCoordinate = 190;
				square[8].xCoordinate = rand() % 190 + 10;
				square[8].yCoordinate = 250;
				square[9].xCoordinate = rand() % 300 + 250;
				square[9].yCoordinate = 250;

				for (i = 0; i < 10; i++)
				{
					square[i].hitcounter = 10;
				}
			}
		}

		for (i = 0; i < 10; i++)
		{
			al_draw_filled_rectangle(square[i].xCoordinate, square[i].yCoordinate, square[i].xCoordinate + 56, square[i].yCoordinate + 42, al_map_rgb(255, 255, 255));

		}
		al_draw_line(x1pos, y1pos, x2pos, y2pos - 50, al_map_rgb(255, 255, 255), 1);
		al_draw_filled_circle(xpos, ypos, 10, al_map_rgb(255, 255, 255));
		for (i = 0; i < 10; i++)
		{
			al_draw_textf(arial, al_map_rgb(0, 0, 0), square[i].xCoordinate + 18, square[i].yCoordinate + 9, 0, "%d", square[i].hitcounter);
		}

		al_draw_textf(arial, al_map_rgb(255, 255, 255), 230, 770, 0, "Score: %d", score);
		al_draw_textf(arial16, al_map_rgb(255, 255, 255), 10, 740, 0, "A - D : Direction");
		al_draw_textf(arial16, al_map_rgb(255, 255, 255), 10, 756, 0, "W : Release Ball");
		al_draw_textf(arial16, al_map_rgb(255, 255, 255), 450, 772, 0, "Reach 30 to WIN!");
		al_draw_textf(arial16, al_map_rgb(255, 255, 255), 10, 772, 0, "ESC : Exit");

		if (score >= 30) {
			finish = 1;
			al_draw_textf(arial90, al_map_rgb(255, 255, 255), 15, 350, 0, "CONGRATULATIONS!");
		}

		al_flip_display();

	}



	system("pause");
	return 0;
}