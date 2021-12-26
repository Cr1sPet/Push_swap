

int joiner (int argc, char *argv[])
{
	int	i;
	char *res;
	char *temp;

	i = 1;
	res = ft_strdup("");
	if (NULL == res)
		exit (1);
	while (i < argc)
	{
		if (argv[i][0])
		{
			temp = res;
			ft_strjoin (res, argv[i]);
			if (NULL == res)
			{
				free (temp);
				exit (1);
			}
		}
		else
		{
			free (temp);
			write_bad_message();
		}
		i++;
	}
}