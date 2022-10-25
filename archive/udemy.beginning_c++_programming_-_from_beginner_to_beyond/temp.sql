create table asunto (
    primary key (num_expediente), -- asunto_id
    foreign key (cliente_id) references cliente(cliente_id),
    fecha_inicio date,
    fecha_finalizacion date,
    estado varchar(255)
)

create table cliente (
    cliente_id int primary key,
    nombre varchar(255),
    dpi varchar(20),
    direccion varchar(255)
)

create table abogado (
    abogado_id int primary key,
    nombre varchar(255),
    dpi varchar(14),
    direccion varchar(255)
)

create table asunto_abogado (
    asunto_abogado_pk primary key (num_expediente, abogado_id),
    num_expediente int,
    abogado_id int,
    asunto_fk references asunto(num_expediente),
    abogado_fk references abogado(abogado_id)
)