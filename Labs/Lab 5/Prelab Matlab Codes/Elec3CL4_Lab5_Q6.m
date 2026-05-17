%% Elec3CL4_Lab5_Q6

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

% print open loop transfer function
title('Open Loop Transfer Function of Phase Lead Lag Compensator:')
disp(G_c_lead_lag*G)