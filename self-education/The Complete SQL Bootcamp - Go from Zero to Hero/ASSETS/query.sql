




select customer_id, staff_id, sum(amount) from payment
where staff_id = 2
group by customer_id, staff_id
having sum(amount) >= 110;

select count(title) from film
where title like 'J%';

select  from customer
where customer_id = max(customer_id)
first_name like 'E%' and 
address_id < 500;