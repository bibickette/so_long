#include "../so_long.h"

t_win	create_window(int height, int width, char *str)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	return((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
}

int main(void)
{
	t_win window;

	window = create_window(350, 350, "Pouet");
	if (!window.mlx_ptr || !window.win_ptr)
	{
		ft_printf("%s", ERROR_MSG);
		return (ERROR);
	}
	mlx_loop(window.mlx_ptr);
	mlx_destroy_window(window.mlx_ptr, window.win_ptr);
    mlx_destroy_display(window.mlx_ptr);
    free(window.mlx_ptr);
}
