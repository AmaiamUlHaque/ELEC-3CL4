%% Elec3CL4_Lab5_Q3

% using "Control System Toolbox"

s = tf('s');

% plant transfer function
G = 4.7 / (s*(s+3.2));

% controller transfer function
kc = 11.33;
z_lead = 4;
p_lead = 9.54;
z_lag = 0.1;
p_lag = 0.01;

G_c_lead = kc * (s+z_lead)/(s+p_lead);
G_c_lag = (s+z_lag)/(s+p_lag);
G_c_lead_lag = G_c_lead * G_c_lag;

% plot root locus
figure
rlocus(G_c_lead*G)
title('Root Locus of Lead Compensated System')
grid on

figure
rlocus(G_c_lead_lag*G)
title('Root Locus of Lead-Lag Compensated System')
grid on





