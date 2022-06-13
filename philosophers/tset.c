#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
	int				num;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				status;
	int				*time_data;
	struct s_philo 	*next;
	struct s_philo 	*prev;
}	t_philo;

typedef struct s_list
{
	int 	time_data[5];
	t_philo *philo;
}	t_list;

int	make_philo(t_list *data)
{
	int		i;
	t_philo	*first_philo;
	t_philo	*prev_philo;

	first_philo = data->philo;
	i = 1;
	while (i < data->time_data[0])
	{
		prev_philo = data->philo;
		data->philo->next = (t_philo *)malloc(sizeof(t_philo));
		if (data->philo->next == NULL)
			return (-1);
		data->philo->next->num = i + 1;
		data->philo->next->status = 0;
		data->philo->next->time_data = data->time_data;
		data->philo->next->prev = prev_philo;
		data->philo = data->philo->next;
		i++;
	}
	data->philo->next = first_philo;
	first_philo->prev = data->philo;
	data->philo = first_philo;
	return (1);
}

int	make_philosophers(t_list *data)
{
	t_philo	*first_philo;

	if (data->time_data[0] == 0)
		return (-1);
	data->philo = (t_philo *)malloc(sizeof(t_philo));
	if (data->philo == NULL)
		return (-1);
	data->philo->num = 1;
	data->philo->time_data = data->time_data;
	data->philo->status = 0;
	data->philo->next = NULL;
	data->philo->prev = NULL;
	if (make_philo(data) == -1)
		return (-1);
	return (1);
}

void *ft(void *data)
{
	t_philo *dataa;

	dataa = (t_philo *)data;
	printf("num : %d\n" ,dataa->num);
	// return (NULL);
}
void	print_philo(t_list data)
{
	int	i;
	t_philo *next_p;
	i = 0;
	next_p = data.philo;
	while (i < data.time_data[0] * 2)
	{
		printf("%d philo fork = %d\n", i, next_p->num);
		next_p = next_p->next;
		i++;
	}
}
int main()
{
	t_list a;
	int i = 0;
	a.time_data[0] = 3;

	make_philosophers(&a);
	while (i < 3)
	{
		pthread_create(&(a.philo->thread),NULL, ft, (void *)(a.philo));
		printf("p : %d\n",a.philo->num);
		a.philo = a.philo->next;
		i++;
	}
	pthread_join(a.philo->thread, 0);
}