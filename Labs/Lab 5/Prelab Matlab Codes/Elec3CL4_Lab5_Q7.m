%% Elec3CL4_Lab5_Q7
% using "Control System Toolbox"

s = tf('s');

% lab station plant transfer function
G = 311.8 / (s*(s+10.62));

% lab station controller transfer function
kc = 1.87;
z_lead = 13.33;
p_lead = 31.31;
z_lag = 0.1;
p_lag = 0.01;

% transfer functions
G_c_lead = kc * (s+z_lead)/(s+p_lead);
G_c_lag = (s+z_lag)/(s+p_lag);
G_c_lead_lag = G_c_lead * G_c_lag;

% print closed loop transfer functions
disp('Closed Loop Transfer Function of Lead Compensator:')
T_lead = feedback(G_c_lead*G, 1)

disp('Closed Loop Transfer Function of Lead-Lag Compensator:')
T_lead_lag = feedback(G_c_lead_lag*G, 1)

% print poles and zeroes
disp('Poles of Lead Compensator:')
pole(T_lead)
disp('Zeroes of Lead Compensator:')
zero(T_lead)

disp('Poles of Lead-Lag Compensator:')
pole(T_lead_lag)
disp('Zeroes of Lead-Lag Compensator:')
zero(T_lead_lag)