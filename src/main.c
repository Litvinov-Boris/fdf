/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:37:11 by svivienn          #+#    #+#             */
/*   Updated: 2019/05/07 20:29:14 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
    void *tmp;
    void *tmp2;

    tmp = mlx_init();
    tmp2 = mlx_new_window(tmp, 500,500, "chto_ty_takoe");
    mlx_loop(tmp);
    return (0);
}