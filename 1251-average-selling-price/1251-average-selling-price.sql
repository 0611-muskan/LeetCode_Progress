select p.product_id,ifnull(round(sum(p.price*u.units)/sum(u.units),2),0) as average_price
from prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND 
u.purchase_date BETWEEN p.start_date AND p.end_date
group by product_id;