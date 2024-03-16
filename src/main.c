#include "../so_long.h"

t_win	create_window(int width, int height, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
}

int main(void)
{
    t_win	window;

  	window = create_window(300, 300, "try");
	while(1)
	{
		
	}
    mlx_destroy_display(window.mlx_ptr);
    free(window.mlx_ptr);
}
