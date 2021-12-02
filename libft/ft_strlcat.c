size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst++ != '\0')
		i++;
	dst--;
	if (i > size)
	{
		i = size;
		size = 1;
	}
	else
		size = size - i;
	while (*src != '\0')
	{
		if (size > 1)
		{
			*dst++ = *src;
			size--;
		}
		src++;
		i++;
	}
	*dst = '\0';
	return (i);
}
